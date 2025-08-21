#ifndef __CBXP_H_
#define __CBXP_H_

#ifdef __cplusplus
extern "C" {
#endif

/*
This is the main interface to CBXP.

The following pointers must be freed after calling this interface to
avoid memory leaks:

  result.result_json

*/
int cbxp(char *result_json_string, const char *p_request_json_string, int length, bool debug);

#ifdef __cplusplus
}
#endif

#pragma export(cbxp)

#endif
