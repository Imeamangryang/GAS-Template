// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attributes/GAS_AttributeSet.h"

void UGAS_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// 여기서 속성(Attribute)의 값을 제한하거나 조정할 수 있습니다.

}

void UGAS_AttributeSet::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	// 속성(Attribute)의 값이 변경된 후에 추가적인 작업을 수행할 수 있습니다.

	Super::PostAttributeChange(Attribute, OldValue, NewValue);

	// Health 속성이 변경되었을 때 OnStaminaChanged 이벤트를 호출합니다.
	if (Attribute == GetHealthAttribute())
	{
		OnHealthChanged.Broadcast(OldValue, NewValue);
	}
}
