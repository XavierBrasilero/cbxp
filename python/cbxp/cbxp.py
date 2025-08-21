import json

from cbxp._C import call_cbxp


class CbxpResult:
    def __init__(
            self,
            request: dict,
            result: dict | None,
            rc: int
    ):
        self.request = request
        self.result = result       

    
def cbxp(request: dict, debug: bool = False) -> dict:
    response = call_cbxp(json.dumps(request), debug=debug)
    return CbxpResult(
        request = request,
        result = json.loads(response['result_json']),
        rc = response['return_code']
    )

def psa(debug: bool = False) -> dict:
    return cbxp( {"control_block": "psa"}, debug=debug).result

def cvt(debug: bool = False) -> dict:
    return cbxp( {"control_block": "cvt"}, debug=debug).result

def ecvt(debug: bool = False) -> dict:
    return cbxp( {"control_block": "ecvt"}, debug=debug).result
