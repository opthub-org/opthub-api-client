# Solution

解

## Properties

Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**match_id** | **str** | 競技のID | 
**participant_type** | [**ParticipantType**](ParticipantType.md) |  | 
**participant_id** | **str** | 参加者のID | 
**trial_no** | **int** | 試行番号 | 
**variable** | **object** | 解空間の変数 | 
**created_at** | **datetime** | 作成日時 | 
**user_id** | **str** | 作成したユーザのID | [optional] 

## Example

```python
from openapi_client.models.solution import Solution

# TODO update the JSON string below
json = "{}"
# create an instance of Solution from a JSON string
solution_instance = Solution.from_json(json)
# print the JSON string representation of the object
print(Solution.to_json())

# convert the object into a dict
solution_dict = solution_instance.to_dict()
# create an instance of Solution from a dict
solution_from_dict = Solution.from_dict(solution_dict)
```
[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


