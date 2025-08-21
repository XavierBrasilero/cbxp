#ifndef __CBXP_RESULT_H_
#define __CBXP_RESULT_H_

typedef struct {
  const char *control_block;
  char *result_json;
  int result_json_length;
  int return_code;
} cbxp_result_t;

#endif