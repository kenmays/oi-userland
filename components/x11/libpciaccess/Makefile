#
# This file and its contents are supplied under the terms of the
# Common Development and Distribution License ("CDDL)". You may
# only use this file in accordance with the terms of the CDDL.
#
# A full copy of the text of the CDDL should have accompanied this
# source. A copy of the CDDL is also available via the Internet at
# http://www.illumos.org/license/CDDL.
#

#
# Copyright (c) 2015 Alexander Pyhalov
# Copyright (c) 2019 Michal Nowak
#

include ../../../make-rules/shared-macros.mk

COMPONENT_NAME=		libpciaccess
COMPONENT_VERSION=	0.14
COMPONENT_PROJECT_URL=	http://xorg.freedesktop.org
COMPONENT_SUMMARY=	scanpci and libpciaccess - generic PCI access software
COMPONENT_SRC=		$(COMPONENT_NAME)-$(COMPONENT_VERSION)
COMPONENT_ARCHIVE=	$(COMPONENT_SRC).tar.bz2
COMPONENT_ARCHIVE_HASH=	\
    sha256:3df543e12afd41fea8eac817e48cbfde5aed8817b81670a4e9e493bb2f5bf2a4
COMPONENT_ARCHIVE_URL=	http://xorg.freedesktop.org/releases/individual/lib/$(COMPONENT_ARCHIVE)
COMPONENT_CLASSIFICATION=	System/Hardware
COMPONENT_FMRI=		diagnostic/scanpci
COMPONENT_LICENSE_FILE=	COPYING
COMPONENT_LICENSE=	MIT

include $(WS_MAKE_RULES)/prep.mk
include $(WS_MAKE_RULES)/configure.mk
include $(WS_MAKE_RULES)/ips.mk

# Missing files in build dir for configure without this.
COMPONENT_PREP_ACTION =        (cd $(@D) && \
                                        libtoolize --automake --copy --force && \
                                        aclocal -Im4 && \
                                        autoheader && \
                                        automake -a -f -c &&\
                                        autoconf )

PATH=$(PATH.gnu)

build:		$(BUILD_32_and_64)

install:	$(INSTALL_32_and_64)

test:		$(NO_TESTS)

# Auto-generated dependencies
REQUIRED_PACKAGES += system/library
