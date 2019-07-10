include $(TOPDIR)/rules.mk
  
PKG_NAME:=practice
PKG_RELEASE:=1
PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)
TARGET_LDFLAGS+= -L$(STAGING_DIR)/usr/lib
LDFLAGS="$(TARGET_LDFLAGS)" -rpath=$(STAGING_DIR)/usr/lib
include $(INCLUDE_DIR)/package.mk

define Package/practice
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libaio
	TITLE:=practice -- practice programs for linux kernel study
endef

define Package/practice/description
		If you can't figure out what this program does, you're probably
		brain-dead and need immediate medical attention.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

	#$(INSTALL_BIN) $(PKG_BUILD_DIR)/globalfifo_epoll $(1)/bin/
define Package/practice/install
	$(INSTALL_DIR) $(1)/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/globalfifo_poll $(1)/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/globalfifo_epoll $(1)/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/globalfifo_fasync $(1)/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/globalfifo_aio $(1)/bin/
	
endef

$(eval $(call BuildPackage,practice))
