#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <syslog.h>
#include <libubox/blobmsg_json.h>
#include "libubus.h"
#include <stdio.h>

#define  TOPIC "/device/auth/"

FILE *fp = NULL;
char schar=',';
enum {
	SMSG_ID,
	SMSG_TOPIC,
	SMSG_MSG,
	__SMSG_MAX
};
enum {
	AUTH_TYPE,
	AUTH_SN,
	AUTH_MAC,
	AUTH_ALLOW,
	__AUTH_MAX
};

static char *ap_topic;
static struct ubus_context *ubus_ctx;
static struct blob_buf b;
static void hello_timer_prt();

enum {
    RETURN_CODE,
    __RETURN_MAX,
};

static const struct blobmsg_policy return_policy[__RETURN_MAX] = {
    [RETURN_CODE] = { .name = "result", .type = BLOBMSG_TYPE_INT32 },
};

static const struct blobmsg_policy smsg_policy[] = {
	[SMSG_ID] = { .name = "id", .type = BLOBMSG_TYPE_INT32 },
	[SMSG_TOPIC] = { .name = "topic", .type = BLOBMSG_TYPE_STRING },
	[SMSG_MSG] = { .name = "msg", .type = BLOBMSG_TYPE_STRING },
};


#define CMD_LINE_LEN        4096


static int hello_smsg(struct ubus_context *ctx, struct ubus_object *obj,
		      struct ubus_request_data *req, const char *method,
		      struct blob_attr *msg)
{
	struct blob_attr *tb[__SMSG_MAX];
	char *msgstr = "(unknown)";
	int sret = 0;
	sret = blobmsg_parse(smsg_policy, ARRAY_SIZE(smsg_policy), tb, blob_data(msg), blob_len(msg));
	/*
	if(tb[SMSG_ID] != NULL){
		id = blobmsg_get_u32(tb[SMSG_ID]);
	}
	*/
	if (tb[SMSG_MSG] != NULL){
		//msg_topic = blobmsg_get_string(tb[SMSG_TOPIC]);
		msgstr = blobmsg_get_string(tb[SMSG_MSG]);
		//syslog(LOG_INFO,"The received topic is : %s\n",msg_topic);
		syslog(LOG_INFO,"This is hello call ,received msg is : %s\n",msgstr);
	}else{
		sret = -1;
	}
	
	blob_buf_init(&b,0);

	if( sret >= 0 ){
		blobmsg_add_u8(&b,"result",1);
	}else{
		blobmsg_add_u8(&b,"result",0);
	}
	ubus_send_reply(ctx,req,b.head);
	
	return 0;
}


static struct uloop_timeout hello_timer = {
	.cb = hello_timer_prt
};

static void hello_timer_prt()
{
		syslog(LOG_INFO,"This is hello_timer printing..........");
		uloop_timeout_set(&hello_timer, 3000);

}

static const struct ubus_method hello_methods[] = {
	UBUS_METHOD("hello_call", hello_smsg, smsg_policy),
};

static struct ubus_object_type apr_object_type =
	UBUS_OBJECT_TYPE("ubus_hello", hello_methods);

static struct ubus_object apr_object = {
	.name = "ubus_hello",
	.type = &apr_object_type,
	.methods = hello_methods,
	.n_methods = ARRAY_SIZE(hello_methods),
};



static void server_main(void)
{
	int ret;
	int count = 0;
agagin:
	ret = ubus_add_object(ubus_ctx, &apr_object);
	if (ret){
		syslog(LOG_ERR,"Failed to add object: %s\n", ubus_strerror(ret));
		ret = ubus_remove_object(ubus_ctx, &apr_object);
		sleep(1);
		count++;
		if(count >= 10){
			return;
		}
		goto agagin;
	}
}


static void ubus_connect_handler(struct ubus_context *ctx)
{
	ubus_ctx = ctx;

	server_main();
	return;
}

static struct ubus_auto_conn conn;

void *init_ubus_hello(){
	uloop_init();
	signal(SIGPIPE, SIG_IGN);
	conn.cb = ubus_connect_handler;
	ubus_auto_connect(&conn);
	uloop_timeout_set(&hello_timer, 5000);

	ubus_add_uloop(ubus_ctx);
	uloop_run();
	//if (ubus_ctx != NULL)
	//	ubus_free(ubus_ctx);
	uloop_done();
	return 0;

}
int main(int argc,char *argv[]){
	init_ubus_hello();
	return 0;
}
