SRC += johanfriis.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
     SRC += dance.c
endif

