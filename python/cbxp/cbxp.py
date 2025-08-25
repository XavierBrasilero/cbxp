import json

from cbxp._C import call_cbxp

class CBXPError(Exception):
    """A class of errors for return codes from the cbxp interface"""
    def __init__(self, return_code, control_block_name):
        self.rc = return_code
        match self.rc:
            case -1:
                message = f"could not obtain control block information for '{control_block_name}'"
            case _:
                message = "an unknown error occurred in control block explorer"
        super().__init__(message)

    

    
def cbxp(control_block_name: str, debug: bool = False) -> dict:
    response = call_cbxp(control_block_name, debug=debug)
    if response['return_code']:
        return CBXPError(control_block_name)
    return json.loads(response['result_json'])
