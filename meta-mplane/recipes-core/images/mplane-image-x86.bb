# Base this image on core-image-minimal
require recipes-core/images/core-image-minimal.bb

# Include modules in rootfs
IMAGE_INSTALL += " \
    bash \
    climp \
    libffi \
    lua \
    lua-argparse \
    lua-luaunit \
    lua-penlight \
    luajit \
    os-release \
    vim \
    virtual/halmplane \
    netopeer2 \
    mplane-server \
    "

# Allow additional packages to be specified from the command line
EXTRA_IMAGE_INSTALL ?= " "

# Append any extra packages specified
IMAGE_INSTALL += "${EXTRA_IMAGE_INSTALL}"

# Set en_US as the default locale
IMAGE_LINGUAS += "en-us"

