#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=globalfifo
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define KernelPackage/globalfifo
  SUBMENU:=practice modules
  TITLE:=Driver for globalfifo
  AUTOLOAD:=$(call AutoLoad,80,globalfifo)
  FILES:=$(PKG_BUILD_DIR)/globalfifo.ko
endef

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
		$(KERNEL_MAKE_FLAGS) \
		SUBDIRS="$(PKG_BUILD_DIR)" \
		EXTRA_CFLAGS="$(BUILDFLAGS)" \
		modules
endef

$(eval $(call KernelPackage,globalfifo))
