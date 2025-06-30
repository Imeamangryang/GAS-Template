// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h" // AttributeSet을 사용하기 위한 헤더 파일
#include "GAS_AttributeSet.generated.h"

// Attribute 변경 이벤트를 위한 Delegate 정의
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChangedEvent, float, OldValue, float, NewValue);

// Attribute를 정의하기 위한 매크로들
// UAttributeSet에 정의되어 있는 매크로로 Getter, setter, initter 등을 자동으로 생성합니다.
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class GASTEMPLATE_API UGAS_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	/*
	 *	속성(Attribute)에 어떤 수정이 일어나기 직전에 호출됩니다. 이 함수는 PreAttributeModify/PostAttributeModify보다 더 하위 레벨에서 동작합니다.
	 *	여기서는 추가적인 컨텍스트가 제공되지 않으며, 실행된 효과, 지속 효과, 효과 제거, 면역 적용, 스택 규칙 변경 등 어떤 것이든 이 함수를 트리거할 수 있습니다.
	 *	이 함수의 목적은 "Health = Clamp(Health, 0, MaxHealth)"와 같이 값을 강제로 제한하는 것이며, "데미지가 적용되면 추가로 무언가를 트리거한다"와 같은 동작을 구현하는 곳이 아닙니다.
	 *
	 *	NewValue는 변경 가능한 참조(mutable reference)이므로, 새로 적용되는 값을 이 함수 내에서 제한(clamp)할 수 있습니다.
	 */
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	/* 속성(Attribute)에 어떤 수정이 발생한 직후에 호출됩니다. */
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;


	// 속성(Attribute) 정의
	UPROPERTY(BlueprintReadOnly, Category = "Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UGAS_AttributeSet, Health) // Health 속성에 대한 Getter, Setter, Initter를 자동으로 생성합니다.

	// Delegate for attribute changes
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedEvent OnHealthChanged;

};
