# openapi_client.SolutionApi

All URIs are relative to *https://example.com/todo/opthub-api-endpoint*

Method | HTTP request | Description
------------- | ------------- | -------------
[**create_solution**](SolutionApi.md#create_solution) | **POST** /solution | 解の作成
[**get_solution**](SolutionApi.md#get_solution) | **GET** /solution | 解の取得


# **create_solution**
> CreateSolutionResponse create_solution(match_id, variable)

解の作成

### Example

* Api Key Authentication (ApiKeyAuth):

```python
import openapi_client
from openapi_client.models.create_solution_response import CreateSolutionResponse
from openapi_client.rest import ApiException
from pprint import pprint

# Defining the host is optional and defaults to https://example.com/todo/opthub-api-endpoint
# See configuration.py for a list of all supported configuration parameters.
configuration = openapi_client.Configuration(
    host = "https://example.com/todo/opthub-api-endpoint"
)

# The client must configure the authentication and authorization parameters
# in accordance with the API server security policy.
# Examples for each auth method are provided below, use the example that
# satisfies your auth use case.

# Configure API key authorization: ApiKeyAuth
configuration.api_key['ApiKeyAuth'] = os.environ["API_KEY"]

# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['ApiKeyAuth'] = 'Bearer'

# Enter a context with an instance of the API client
with openapi_client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = openapi_client.SolutionApi(api_client)
    match_id = '5d7fc778-3e59-4128-a797-2e423c0aa461' # str | 競技のID
    variable = None # object | 解空間の変数

    try:
        # 解の作成
        api_response = api_instance.create_solution(match_id, variable)
        print("The response of SolutionApi->create_solution:\n")
        pprint(api_response)
    except Exception as e:
        print("Exception when calling SolutionApi->create_solution: %s\n" % e)
```



### Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **match_id** | **str**| 競技のID | 
 **variable** | [**object**](.md)| 解空間の変数 | 

### Return type

[**CreateSolutionResponse**](CreateSolutionResponse.md)

### Authorization

[ApiKeyAuth](../README.md#ApiKeyAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

### HTTP response details

| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | Successful operation |  -  |
**0** | successful operation |  -  |

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **get_solution**
> Solution get_solution(match_id, participant_id, trial_no)

解の取得

### Example

* Api Key Authentication (ApiKeyAuth):

```python
import openapi_client
from openapi_client.models.solution import Solution
from openapi_client.rest import ApiException
from pprint import pprint

# Defining the host is optional and defaults to https://example.com/todo/opthub-api-endpoint
# See configuration.py for a list of all supported configuration parameters.
configuration = openapi_client.Configuration(
    host = "https://example.com/todo/opthub-api-endpoint"
)

# The client must configure the authentication and authorization parameters
# in accordance with the API server security policy.
# Examples for each auth method are provided below, use the example that
# satisfies your auth use case.

# Configure API key authorization: ApiKeyAuth
configuration.api_key['ApiKeyAuth'] = os.environ["API_KEY"]

# Uncomment below to setup prefix (e.g. Bearer) for API key, if needed
# configuration.api_key_prefix['ApiKeyAuth'] = 'Bearer'

# Enter a context with an instance of the API client
with openapi_client.ApiClient(configuration) as api_client:
    # Create an instance of the API class
    api_instance = openapi_client.SolutionApi(api_client)
    match_id = '5d7fc778-3e59-4128-a797-2e423c0aa461' # str | 競技のID
    participant_id = '912f548d-2bbe-48ab-90ce-e96dae38377d' # str | 参加者のID
    trial_no = 4 # int | 試行番号

    try:
        # 解の取得
        api_response = api_instance.get_solution(match_id, participant_id, trial_no)
        print("The response of SolutionApi->get_solution:\n")
        pprint(api_response)
    except Exception as e:
        print("Exception when calling SolutionApi->get_solution: %s\n" % e)
```



### Parameters


Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
 **match_id** | **str**| 競技のID | 
 **participant_id** | **str**| 参加者のID | 
 **trial_no** | **int**| 試行番号 | 

### Return type

[**Solution**](Solution.md)

### Authorization

[ApiKeyAuth](../README.md#ApiKeyAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

### HTTP response details

| Status code | Description | Response headers |
|-------------|-------------|------------------|
**200** | Successful operation |  -  |
**0** | successful operation |  -  |

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

