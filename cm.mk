# Inherit from hardware-specific part of the product configuration
$(call inherit-product, device/nubia/nx511j/full_nx511j.mk)

# Inherit some common Mokee stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE       := nx511j
PRODUCT_NAME         := cm_nx511j
PRODUCT_BRAND        := nubia
PRODUCT_MODEL        := NX511J
PRODUCT_MANUFACTURER := nubia
