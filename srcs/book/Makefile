#
# Copyright (C) 2006-2009 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/kernel.mk

PKG_NAME:=book
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define KernelPackage/book
  SUBMENU:=practice modules
  TITLE:=Driver for Practice
  AUTOLOAD:=$(call AutoLoad,70,book)
  FILES:=$(PKG_BUILD_DIR)/book.ko
endef

define Build/Compile
	$(MAKE) -C "$(LINUX_DIR)" \
		$(KERNEL_MAKE_FLAGS) \
		SUBDIRS="$(PKG_BUILD_DIR)" \
		EXTRA_CFLAGS="$(BUILDFLAGS)" \
		modules
endef

$(eval $(call KernelPackage,book))
