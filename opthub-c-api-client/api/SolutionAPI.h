#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/create_solution_response.h"
#include "../model/solution.h"


// 解の作成
//
create_solution_response_t*
SolutionAPI_createSolution(apiClient_t *apiClient, char *matchId, variable);


// 解の取得
//
solution_t*
SolutionAPI_getSolution(apiClient_t *apiClient, char *matchId, char *participantId, int *trialNo);


