import json

from cbxp._C import call_cbxp


class CbxpResult:
    def __init__(
            self,
            control_block: str,
            result: dict | None,
            rc: int
    ):
        self.control_block = control_block
        self.result = result 
        self.return_code = rc      

    
def cbxp(control_block: str, debug: bool = False) -> dict:
    response = call_cbxp(control_block, debug=debug)
    if response['result_json'] is None:
        result_json = None
    else:
        result_json = json.loads(response['result_json'])
    return CbxpResult(
        control_block = control_block,
        result = result_json,
        rc = response['return_code']
    )

def psa(debug: bool = False) -> dict:
    return cbxp("psa", debug=debug).result

def cvt(debug: bool = False) -> dict:
    return cbxp("cvt", debug=debug).result

def ecvt(debug: bool = False) -> dict:
    return cbxp("ecvt", debug=debug).result
