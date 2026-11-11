

#define __weak   __attribute__((weak))





typedef enum
{
  U_OK       = 0x00U,
  U_ERROR    = 0x01U,
  U_BUSY     = 0x02U,
  U_TIMEOUT  = 0x03U
} U_StatusTypeDef;