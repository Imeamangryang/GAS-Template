#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_Test.generated.h"

/**
* 
*/
UCLASS()
class GASTEMPLATE_API UGA_Test : public UGameplayAbility
{
GENERATED_BODY()


public:

	UGA_Test();

	/** 이 능력을 지금 활성화할 수 있는지 여부를 반환합니다. 부작용은 없습니다. */
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

	/** 실행당 인스턴스화된 능력을 제거합니다. 액터당 인스턴스화된 능력은 '재설정'해야 합니다. 활성 상태의 능력 상태 태스크는 'OnAbilityStateInterrupted' 이벤트를 수신합니다. 비인스턴스 능력 - 무엇을 할 수 있을까요? */
	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) override;

	/** 능력을 커밋합니다. */
	virtual bool CommitAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) override;

	/** 실제로 Ability를 활성화합니다. 이 메서드를 직접 호출하지 마세요. */
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	/** Ability가 정상적으로 또는 비정상적으로 종료되었을 때 호출되는 네이티브 함수입니다. bReplicate가 true로 설정된 경우, 클라이언트/서버에 종료를 복제하려고 시도합니다. */
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
};
