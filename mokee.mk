$(call inherit-product, device/nubia/nx511j/full_nx511j.mk)

# Inherit some common CM stuff.
$(call inherit-product, vendor/mk/config/common_full_phone.mk)

PRODUCT_RELEASE_NAME := Nubia Z9 mini
PRODUCT_NAME := mk_nx511j
PRODUCT_MODEL := NX511J

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRODUCT_NAME=NX511J

PRODUCT_GMS_CLIENTID_BASE := android-zte
