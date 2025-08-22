import json

from cbxp._C import call_cbxp
    

    
def cbxp(control_block_name: str, debug: bool = False) -> dict:
    response = call_cbxp(control_block_name, debug=debug)
    if response['return_code']:
        return {"error": f"could not obtain control block information for '{control_block_name}'"}
    return json.loads(response['result_json'])
