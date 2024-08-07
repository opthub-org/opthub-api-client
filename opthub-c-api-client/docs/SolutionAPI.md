# SolutionAPI

All URIs are relative to *https://example.com/todo/opthub-api-endpoint*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SolutionAPI_createSolution**](SolutionAPI.md#SolutionAPI_createSolution) | **POST** /solution | 解の作成
[**SolutionAPI_getSolution**](SolutionAPI.md#SolutionAPI_getSolution) | **GET** /solution | 解の取得


# **SolutionAPI_createSolution**
```c
// 解の作成
//
create_solution_response_t* SolutionAPI_createSolution(apiClient_t *apiClient, char *matchId, variable);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**matchId** | **char \*** | 競技のID | 
**variable** |  | 解空間の変数 | 

### Return type

[create_solution_response_t](create_solution_response.md) *


### Authorization

[ApiKeyAuth](../README.md#ApiKeyAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SolutionAPI_getSolution**
```c
// 解の取得
//
solution_t* SolutionAPI_getSolution(apiClient_t *apiClient, char *matchId, char *participantId, int *trialNo);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**matchId** | **char \*** | 競技のID | 
**participantId** | **char \*** | 参加者のID | 
**trialNo** | **int \*** | 試行番号 | 

### Return type

[solution_t](solution.md) *


### Authorization

[ApiKeyAuth](../README.md#ApiKeyAuth)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

