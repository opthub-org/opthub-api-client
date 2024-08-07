/**
 * OptHub REST API
 * OptHubの公開REST APIです。
 *
 * The version of the OpenAPI document: 0.1.0
 * Contact: dev@opthub.ai
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 7.8.0-SNAPSHOT.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */

/*
 * Solution.h
 *
 * 解
 */

#ifndef ORG_OPENAPITOOLS_CLIENT_MODEL_Solution_H_
#define ORG_OPENAPITOOLS_CLIENT_MODEL_Solution_H_


#include "CppRestOpenAPIClient/ModelBase.h"

#include "CppRestOpenAPIClient/model/ParticipantType.h"
#include <cpprest/details/basic_types.h>
#include "CppRestOpenAPIClient/Object.h"

namespace org {
namespace openapitools {
namespace client {
namespace model {



/// <summary>
/// 解
/// </summary>
class  Solution
    : public ModelBase
{
public:
    Solution();
    virtual ~Solution();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    bool fromJson(const web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    bool fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Solution members

    /// <summary>
    /// 競技のID
    /// </summary>
    utility::string_t getMatchId() const;
    bool matchIdIsSet() const;
    void unsetMatchId();

    void setMatchId(const utility::string_t& value);

    /// <summary>
    /// 
    /// </summary>
    std::shared_ptr<ParticipantType> getParticipantType() const;
    bool participantTypeIsSet() const;
    void unsetParticipantType();

    void setParticipantType(const std::shared_ptr<ParticipantType>& value);

    /// <summary>
    /// 参加者のID
    /// </summary>
    utility::string_t getParticipantId() const;
    bool participantIdIsSet() const;
    void unsetParticipantId();

    void setParticipantId(const utility::string_t& value);

    /// <summary>
    /// 試行番号
    /// </summary>
    int32_t getTrialNo() const;
    bool trialNoIsSet() const;
    void unsetTrialNo();

    void setTrialNo(int32_t value);

    /// <summary>
    /// 解空間の変数
    /// </summary>
    std::shared_ptr<Object> getVariable() const;
    bool variableIsSet() const;
    void unsetVariable();

    void setVariable(const std::shared_ptr<Object>& value);

    /// <summary>
    /// 作成日時
    /// </summary>
    utility::datetime getCreatedAt() const;
    bool createdAtIsSet() const;
    void unsetCreatedAt();

    void setCreatedAt(const utility::datetime& value);

    /// <summary>
    /// 作成したユーザのID
    /// </summary>
    utility::string_t getUserId() const;
    bool userIdIsSet() const;
    void unsetUserId();

    void setUserId(const utility::string_t& value);


protected:
    utility::string_t m_MatchId;
    bool m_MatchIdIsSet;
    std::shared_ptr<ParticipantType> m_ParticipantType;
    bool m_ParticipantTypeIsSet;
    utility::string_t m_ParticipantId;
    bool m_ParticipantIdIsSet;
    int32_t m_TrialNo;
    bool m_TrialNoIsSet;
    std::shared_ptr<Object> m_Variable;
    bool m_VariableIsSet;
    utility::datetime m_CreatedAt;
    bool m_CreatedAtIsSet;
    utility::string_t m_UserId;
    bool m_UserIdIsSet;
};


}
}
}
}

#endif /* ORG_OPENAPITOOLS_CLIENT_MODEL_Solution_H_ */
