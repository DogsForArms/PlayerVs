// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Grippables/GrippableActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGrippableActor() {}
// Cross Module References
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_AGrippableActor_NoRegister();
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_AGrippableActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VRExpansionPlugin();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_AdvancedGripSettings();
	VREXPANSIONPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FBPAdvGripSettings();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_ClosestGripSlotInRange();
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_UGripMotionControllerComponent_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_DenyGripping();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_GetGripStiffnessAndDamping();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_GetInteractionSettings();
	VREXPANSIONPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FBPInteractionSettings();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_GetPrimaryGripType();
	VREXPANSIONPLUGIN_API UEnum* Z_Construct_UEnum_VRExpansionPlugin_EGripCollisionType();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_GripBreakDistance();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_GripLateUpdateSetting();
	VREXPANSIONPLUGIN_API UEnum* Z_Construct_UEnum_VRExpansionPlugin_EGripLateUpdateSettings();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_GripMovementReplicationType();
	VREXPANSIONPLUGIN_API UEnum* Z_Construct_UEnum_VRExpansionPlugin_EGripMovementReplicationSettings();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_IsHeld();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_IsInteractible();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnChildGrip();
	VREXPANSIONPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FBPActorGripInformation();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnChildGripRelease();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnEndSecondaryUsed();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnEndUsed();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnGrip();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnGripRelease();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnInput();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_EInputEvent();
	INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnSecondaryGrip();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnSecondaryGripRelease();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnSecondaryUsed();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_OnUsed();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_RequestsSocketing();
	VREXPANSIONPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FTransform_NetQuantize();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_SecondaryGripType();
	VREXPANSIONPLUGIN_API UEnum* Z_Construct_UEnum_VRExpansionPlugin_ESecondaryGripType();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_SetHeld();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_SimulateOnDrop();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_TeleportBehavior();
	VREXPANSIONPLUGIN_API UEnum* Z_Construct_UEnum_VRExpansionPlugin_EGripInterfaceTeleportBehavior();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_AGrippableActor_TickGrip();
	VREXPANSIONPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FBPInterfaceProperties();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_UVRGripInterface_NoRegister();
	GAMEPLAYTAGS_API UClass* Z_Construct_UClass_UGameplayTagAssetInterface_NoRegister();
// End Cross Module References
	static FName NAME_AGrippableActor_AdvancedGripSettings = FName(TEXT("AdvancedGripSettings"));
	FBPAdvGripSettings AGrippableActor::AdvancedGripSettings()
	{
		GrippableActor_eventAdvancedGripSettings_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_AdvancedGripSettings),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_ClosestGripSlotInRange = FName(TEXT("ClosestGripSlotInRange"));
	void AGrippableActor::ClosestGripSlotInRange(FVector WorldLocation, bool bSecondarySlot, bool& bHadSlotInRange, FTransform& SlotWorldTransform, UGripMotionControllerComponent* CallingController, FName OverridePrefix)
	{
		GrippableActor_eventClosestGripSlotInRange_Parms Parms;
		Parms.WorldLocation=WorldLocation;
		Parms.bSecondarySlot=bSecondarySlot ? true : false;
		Parms.bHadSlotInRange=bHadSlotInRange ? true : false;
		Parms.SlotWorldTransform=SlotWorldTransform;
		Parms.CallingController=CallingController;
		Parms.OverridePrefix=OverridePrefix;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_ClosestGripSlotInRange),&Parms);
		bHadSlotInRange=Parms.bHadSlotInRange;
		SlotWorldTransform=Parms.SlotWorldTransform;
	}
	static FName NAME_AGrippableActor_DenyGripping = FName(TEXT("DenyGripping"));
	bool AGrippableActor::DenyGripping()
	{
		GrippableActor_eventDenyGripping_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_DenyGripping),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_GetGripStiffnessAndDamping = FName(TEXT("GetGripStiffnessAndDamping"));
	void AGrippableActor::GetGripStiffnessAndDamping(float& GripStiffnessOut, float& GripDampingOut)
	{
		GrippableActor_eventGetGripStiffnessAndDamping_Parms Parms;
		Parms.GripStiffnessOut=GripStiffnessOut;
		Parms.GripDampingOut=GripDampingOut;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_GetGripStiffnessAndDamping),&Parms);
		GripStiffnessOut=Parms.GripStiffnessOut;
		GripDampingOut=Parms.GripDampingOut;
	}
	static FName NAME_AGrippableActor_GetInteractionSettings = FName(TEXT("GetInteractionSettings"));
	FBPInteractionSettings AGrippableActor::GetInteractionSettings()
	{
		GrippableActor_eventGetInteractionSettings_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_GetInteractionSettings),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_GetPrimaryGripType = FName(TEXT("GetPrimaryGripType"));
	EGripCollisionType AGrippableActor::GetPrimaryGripType(bool bIsSlot)
	{
		GrippableActor_eventGetPrimaryGripType_Parms Parms;
		Parms.bIsSlot=bIsSlot ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_GetPrimaryGripType),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_GripBreakDistance = FName(TEXT("GripBreakDistance"));
	float AGrippableActor::GripBreakDistance()
	{
		GrippableActor_eventGripBreakDistance_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_GripBreakDistance),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_GripLateUpdateSetting = FName(TEXT("GripLateUpdateSetting"));
	EGripLateUpdateSettings AGrippableActor::GripLateUpdateSetting()
	{
		GrippableActor_eventGripLateUpdateSetting_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_GripLateUpdateSetting),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_GripMovementReplicationType = FName(TEXT("GripMovementReplicationType"));
	EGripMovementReplicationSettings AGrippableActor::GripMovementReplicationType()
	{
		GrippableActor_eventGripMovementReplicationType_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_GripMovementReplicationType),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_IsHeld = FName(TEXT("IsHeld"));
	void AGrippableActor::IsHeld(UGripMotionControllerComponent*& HoldingController, bool& bIsHeld)
	{
		GrippableActor_eventIsHeld_Parms Parms;
		Parms.HoldingController=HoldingController;
		Parms.bIsHeld=bIsHeld ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_IsHeld),&Parms);
		HoldingController=Parms.HoldingController;
		bIsHeld=Parms.bIsHeld;
	}
	static FName NAME_AGrippableActor_IsInteractible = FName(TEXT("IsInteractible"));
	bool AGrippableActor::IsInteractible()
	{
		GrippableActor_eventIsInteractible_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_IsInteractible),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_OnChildGrip = FName(TEXT("OnChildGrip"));
	void AGrippableActor::OnChildGrip(UGripMotionControllerComponent* GrippingController, FBPActorGripInformation const& GripInformation)
	{
		GrippableActor_eventOnChildGrip_Parms Parms;
		Parms.GrippingController=GrippingController;
		Parms.GripInformation=GripInformation;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnChildGrip),&Parms);
	}
	static FName NAME_AGrippableActor_OnChildGripRelease = FName(TEXT("OnChildGripRelease"));
	void AGrippableActor::OnChildGripRelease(UGripMotionControllerComponent* ReleasingController, FBPActorGripInformation const& GripInformation, bool bWasSocketed)
	{
		GrippableActor_eventOnChildGripRelease_Parms Parms;
		Parms.ReleasingController=ReleasingController;
		Parms.GripInformation=GripInformation;
		Parms.bWasSocketed=bWasSocketed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnChildGripRelease),&Parms);
	}
	static FName NAME_AGrippableActor_OnEndSecondaryUsed = FName(TEXT("OnEndSecondaryUsed"));
	void AGrippableActor::OnEndSecondaryUsed()
	{
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnEndSecondaryUsed),NULL);
	}
	static FName NAME_AGrippableActor_OnEndUsed = FName(TEXT("OnEndUsed"));
	void AGrippableActor::OnEndUsed()
	{
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnEndUsed),NULL);
	}
	static FName NAME_AGrippableActor_OnGrip = FName(TEXT("OnGrip"));
	void AGrippableActor::OnGrip(UGripMotionControllerComponent* GrippingController, FBPActorGripInformation const& GripInformation)
	{
		GrippableActor_eventOnGrip_Parms Parms;
		Parms.GrippingController=GrippingController;
		Parms.GripInformation=GripInformation;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnGrip),&Parms);
	}
	static FName NAME_AGrippableActor_OnGripRelease = FName(TEXT("OnGripRelease"));
	void AGrippableActor::OnGripRelease(UGripMotionControllerComponent* ReleasingController, FBPActorGripInformation const& GripInformation, bool bWasSocketed)
	{
		GrippableActor_eventOnGripRelease_Parms Parms;
		Parms.ReleasingController=ReleasingController;
		Parms.GripInformation=GripInformation;
		Parms.bWasSocketed=bWasSocketed ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnGripRelease),&Parms);
	}
	static FName NAME_AGrippableActor_OnInput = FName(TEXT("OnInput"));
	void AGrippableActor::OnInput(FKey Key, EInputEvent KeyEvent)
	{
		GrippableActor_eventOnInput_Parms Parms;
		Parms.Key=Key;
		Parms.KeyEvent=KeyEvent;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnInput),&Parms);
	}
	static FName NAME_AGrippableActor_OnSecondaryGrip = FName(TEXT("OnSecondaryGrip"));
	void AGrippableActor::OnSecondaryGrip(USceneComponent* SecondaryGripComponent, FBPActorGripInformation const& GripInformation)
	{
		GrippableActor_eventOnSecondaryGrip_Parms Parms;
		Parms.SecondaryGripComponent=SecondaryGripComponent;
		Parms.GripInformation=GripInformation;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnSecondaryGrip),&Parms);
	}
	static FName NAME_AGrippableActor_OnSecondaryGripRelease = FName(TEXT("OnSecondaryGripRelease"));
	void AGrippableActor::OnSecondaryGripRelease(USceneComponent* ReleasingSecondaryGripComponent, FBPActorGripInformation const& GripInformation)
	{
		GrippableActor_eventOnSecondaryGripRelease_Parms Parms;
		Parms.ReleasingSecondaryGripComponent=ReleasingSecondaryGripComponent;
		Parms.GripInformation=GripInformation;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnSecondaryGripRelease),&Parms);
	}
	static FName NAME_AGrippableActor_OnSecondaryUsed = FName(TEXT("OnSecondaryUsed"));
	void AGrippableActor::OnSecondaryUsed()
	{
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnSecondaryUsed),NULL);
	}
	static FName NAME_AGrippableActor_OnUsed = FName(TEXT("OnUsed"));
	void AGrippableActor::OnUsed()
	{
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_OnUsed),NULL);
	}
	static FName NAME_AGrippableActor_RequestsSocketing = FName(TEXT("RequestsSocketing"));
	bool AGrippableActor::RequestsSocketing(USceneComponent*& ParentToSocketTo, FName& OptionalSocketName, FTransform_NetQuantize& RelativeTransform)
	{
		GrippableActor_eventRequestsSocketing_Parms Parms;
		Parms.ParentToSocketTo=ParentToSocketTo;
		Parms.OptionalSocketName=OptionalSocketName;
		Parms.RelativeTransform=RelativeTransform;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_RequestsSocketing),&Parms);
		ParentToSocketTo=Parms.ParentToSocketTo;
		OptionalSocketName=Parms.OptionalSocketName;
		RelativeTransform=Parms.RelativeTransform;
		return !!Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_SecondaryGripType = FName(TEXT("SecondaryGripType"));
	ESecondaryGripType AGrippableActor::SecondaryGripType()
	{
		GrippableActor_eventSecondaryGripType_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_SecondaryGripType),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_SetHeld = FName(TEXT("SetHeld"));
	void AGrippableActor::SetHeld(UGripMotionControllerComponent* HoldingController, bool bIsHeld)
	{
		GrippableActor_eventSetHeld_Parms Parms;
		Parms.HoldingController=HoldingController;
		Parms.bIsHeld=bIsHeld ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_SetHeld),&Parms);
	}
	static FName NAME_AGrippableActor_SimulateOnDrop = FName(TEXT("SimulateOnDrop"));
	bool AGrippableActor::SimulateOnDrop()
	{
		GrippableActor_eventSimulateOnDrop_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_SimulateOnDrop),&Parms);
		return !!Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_TeleportBehavior = FName(TEXT("TeleportBehavior"));
	EGripInterfaceTeleportBehavior AGrippableActor::TeleportBehavior()
	{
		GrippableActor_eventTeleportBehavior_Parms Parms;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_TeleportBehavior),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AGrippableActor_TickGrip = FName(TEXT("TickGrip"));
	void AGrippableActor::TickGrip(UGripMotionControllerComponent* GrippingController, FBPActorGripInformation const& GripInformation, float DeltaTime)
	{
		GrippableActor_eventTickGrip_Parms Parms;
		Parms.GrippingController=GrippingController;
		Parms.GripInformation=GripInformation;
		Parms.DeltaTime=DeltaTime;
		ProcessEvent(FindFunctionChecked(NAME_AGrippableActor_TickGrip),&Parms);
	}
	void AGrippableActor::StaticRegisterNativesAGrippableActor()
	{
		UClass* Class = AGrippableActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AdvancedGripSettings", &AGrippableActor::execAdvancedGripSettings },
			{ "ClosestGripSlotInRange", &AGrippableActor::execClosestGripSlotInRange },
			{ "DenyGripping", &AGrippableActor::execDenyGripping },
			{ "GetGripStiffnessAndDamping", &AGrippableActor::execGetGripStiffnessAndDamping },
			{ "GetInteractionSettings", &AGrippableActor::execGetInteractionSettings },
			{ "GetPrimaryGripType", &AGrippableActor::execGetPrimaryGripType },
			{ "GripBreakDistance", &AGrippableActor::execGripBreakDistance },
			{ "GripLateUpdateSetting", &AGrippableActor::execGripLateUpdateSetting },
			{ "GripMovementReplicationType", &AGrippableActor::execGripMovementReplicationType },
			{ "IsHeld", &AGrippableActor::execIsHeld },
			{ "IsInteractible", &AGrippableActor::execIsInteractible },
			{ "OnChildGrip", &AGrippableActor::execOnChildGrip },
			{ "OnChildGripRelease", &AGrippableActor::execOnChildGripRelease },
			{ "OnEndSecondaryUsed", &AGrippableActor::execOnEndSecondaryUsed },
			{ "OnEndUsed", &AGrippableActor::execOnEndUsed },
			{ "OnGrip", &AGrippableActor::execOnGrip },
			{ "OnGripRelease", &AGrippableActor::execOnGripRelease },
			{ "OnInput", &AGrippableActor::execOnInput },
			{ "OnSecondaryGrip", &AGrippableActor::execOnSecondaryGrip },
			{ "OnSecondaryGripRelease", &AGrippableActor::execOnSecondaryGripRelease },
			{ "OnSecondaryUsed", &AGrippableActor::execOnSecondaryUsed },
			{ "OnUsed", &AGrippableActor::execOnUsed },
			{ "RequestsSocketing", &AGrippableActor::execRequestsSocketing },
			{ "SecondaryGripType", &AGrippableActor::execSecondaryGripType },
			{ "SetHeld", &AGrippableActor::execSetHeld },
			{ "SimulateOnDrop", &AGrippableActor::execSimulateOnDrop },
			{ "TeleportBehavior", &AGrippableActor::execTeleportBehavior },
			{ "TickGrip", &AGrippableActor::execTickGrip },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_AdvancedGripSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventAdvancedGripSettings_Parms, ReturnValue), Z_Construct_UScriptStruct_FBPAdvGripSettings, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Get the advanced physics settings for this grip" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "AdvancedGripSettings", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventAdvancedGripSettings_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_ClosestGripSlotInRange()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_OverridePrefix = { UE4CodeGen_Private::EPropertyClass::Name, "OverridePrefix", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventClosestGripSlotInRange_Parms, OverridePrefix), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CallingController_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CallingController = { UE4CodeGen_Private::EPropertyClass::Object, "CallingController", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventClosestGripSlotInRange_Parms, CallingController), Z_Construct_UClass_UGripMotionControllerComponent_NoRegister, METADATA_PARAMS(NewProp_CallingController_MetaData, ARRAY_COUNT(NewProp_CallingController_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_SlotWorldTransform = { UE4CodeGen_Private::EPropertyClass::Struct, "SlotWorldTransform", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventClosestGripSlotInRange_Parms, SlotWorldTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
			auto NewProp_bHadSlotInRange_SetBit = [](void* Obj){ ((GrippableActor_eventClosestGripSlotInRange_Parms*)Obj)->bHadSlotInRange = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bHadSlotInRange = { UE4CodeGen_Private::EPropertyClass::Bool, "bHadSlotInRange", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventClosestGripSlotInRange_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bHadSlotInRange_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			auto NewProp_bSecondarySlot_SetBit = [](void* Obj){ ((GrippableActor_eventClosestGripSlotInRange_Parms*)Obj)->bSecondarySlot = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bSecondarySlot = { UE4CodeGen_Private::EPropertyClass::Bool, "bSecondarySlot", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventClosestGripSlotInRange_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bSecondarySlot_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorldLocation = { UE4CodeGen_Private::EPropertyClass::Struct, "WorldLocation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventClosestGripSlotInRange_Parms, WorldLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OverridePrefix,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_CallingController,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SlotWorldTransform,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bHadSlotInRange,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bSecondarySlot,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WorldLocation,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "CPP_Default_OverridePrefix", "None" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Get closest primary slot in range" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "ClosestGripSlotInRange", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0CC20C00, sizeof(GrippableActor_eventClosestGripSlotInRange_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_DenyGripping()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((GrippableActor_eventDenyGripping_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventDenyGripping_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "DisplayName", "IsDenyingGrips" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Set up as deny instead of allow so that default allows for gripping" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "DenyGripping", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventDenyGripping_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_GetGripStiffnessAndDamping()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GripDampingOut = { UE4CodeGen_Private::EPropertyClass::Float, "GripDampingOut", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventGetGripStiffnessAndDamping_Parms, GripDampingOut), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GripStiffnessOut = { UE4CodeGen_Private::EPropertyClass::Float, "GripStiffnessOut", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventGetGripStiffnessAndDamping_Parms, GripStiffnessOut), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripDampingOut,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripStiffnessOut,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "What grip stiffness and damping to use if using a physics constraint" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "GetGripStiffnessAndDamping", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C420C00, sizeof(GrippableActor_eventGetGripStiffnessAndDamping_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_GetInteractionSettings()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventGetInteractionSettings_Parms, ReturnValue), Z_Construct_UScriptStruct_FBPInteractionSettings, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Get interactable settings" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "GetInteractionSettings", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventGetInteractionSettings_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_GetPrimaryGripType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Enum, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventGetPrimaryGripType_Parms, ReturnValue), Z_Construct_UEnum_VRExpansionPlugin_EGripCollisionType, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			auto NewProp_bIsSlot_SetBit = [](void* Obj){ ((GrippableActor_eventGetPrimaryGripType_Parms*)Obj)->bIsSlot = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsSlot = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsSlot", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventGetPrimaryGripType_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bIsSlot_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Underlying,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bIsSlot,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Grip type to use" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "GetPrimaryGripType", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventGetPrimaryGripType_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_GripBreakDistance()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Float, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventGripBreakDistance_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "What distance to break a grip at (only relevent with physics enabled grips" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "GripBreakDistance", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventGripBreakDistance_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_GripLateUpdateSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Enum, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventGripLateUpdateSetting_Parms, ReturnValue), Z_Construct_UEnum_VRExpansionPlugin_EGripLateUpdateSettings, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Define the late update setting" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "GripLateUpdateSetting", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventGripLateUpdateSetting_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_GripMovementReplicationType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Enum, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventGripMovementReplicationType_Parms, ReturnValue), Z_Construct_UEnum_VRExpansionPlugin_EGripMovementReplicationSettings, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Define which movement repliation setting to use" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "GripMovementReplicationType", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventGripMovementReplicationType_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_IsHeld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_bIsHeld_SetBit = [](void* Obj){ ((GrippableActor_eventIsHeld_Parms*)Obj)->bIsHeld = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsHeld = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsHeld", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventIsHeld_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bIsHeld_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HoldingController_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HoldingController = { UE4CodeGen_Private::EPropertyClass::Object, "HoldingController", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080180, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventIsHeld_Parms, HoldingController), Z_Construct_UClass_UGripMotionControllerComponent_NoRegister, METADATA_PARAMS(NewProp_HoldingController_MetaData, ARRAY_COUNT(NewProp_HoldingController_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bIsHeld,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HoldingController,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Returns if the object is held and if so, which pawn is holding it" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "IsHeld", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C420C00, sizeof(GrippableActor_eventIsHeld_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_IsInteractible()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((GrippableActor_eventIsInteractible_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventIsInteractible_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Check if the object is an interactable" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "IsInteractible", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventIsInteractible_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnChildGrip()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GripInformation_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GripInformation = { UE4CodeGen_Private::EPropertyClass::Struct, "GripInformation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnChildGrip_Parms, GripInformation), Z_Construct_UScriptStruct_FBPActorGripInformation, METADATA_PARAMS(NewProp_GripInformation_MetaData, ARRAY_COUNT(NewProp_GripInformation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrippingController_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GrippingController = { UE4CodeGen_Private::EPropertyClass::Object, "GrippingController", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnChildGrip_Parms, GrippingController), Z_Construct_UClass_UGripMotionControllerComponent_NoRegister, METADATA_PARAMS(NewProp_GrippingController_MetaData, ARRAY_COUNT(NewProp_GrippingController_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripInformation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GrippingController,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Event triggered on the interfaced object when child component is gripped" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnChildGrip", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420C00, sizeof(GrippableActor_eventOnChildGrip_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnChildGripRelease()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_bWasSocketed_SetBit = [](void* Obj){ ((GrippableActor_eventOnChildGripRelease_Parms*)Obj)->bWasSocketed = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bWasSocketed = { UE4CodeGen_Private::EPropertyClass::Bool, "bWasSocketed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventOnChildGripRelease_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bWasSocketed_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GripInformation_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GripInformation = { UE4CodeGen_Private::EPropertyClass::Struct, "GripInformation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnChildGripRelease_Parms, GripInformation), Z_Construct_UScriptStruct_FBPActorGripInformation, METADATA_PARAMS(NewProp_GripInformation_MetaData, ARRAY_COUNT(NewProp_GripInformation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReleasingController_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReleasingController = { UE4CodeGen_Private::EPropertyClass::Object, "ReleasingController", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnChildGripRelease_Parms, ReleasingController), Z_Construct_UClass_UGripMotionControllerComponent_NoRegister, METADATA_PARAMS(NewProp_ReleasingController_MetaData, ARRAY_COUNT(NewProp_ReleasingController_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bWasSocketed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripInformation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReleasingController,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Event triggered on the interfaced object when child component is released" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnChildGripRelease", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420C00, sizeof(GrippableActor_eventOnChildGripRelease_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnEndSecondaryUsed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Call to stop using an object" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnEndSecondaryUsed", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnEndUsed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Call to stop using an object" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnEndUsed", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnGrip()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GripInformation_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GripInformation = { UE4CodeGen_Private::EPropertyClass::Struct, "GripInformation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnGrip_Parms, GripInformation), Z_Construct_UScriptStruct_FBPActorGripInformation, METADATA_PARAMS(NewProp_GripInformation_MetaData, ARRAY_COUNT(NewProp_GripInformation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrippingController_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GrippingController = { UE4CodeGen_Private::EPropertyClass::Object, "GrippingController", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnGrip_Parms, GrippingController), Z_Construct_UClass_UGripMotionControllerComponent_NoRegister, METADATA_PARAMS(NewProp_GrippingController_MetaData, ARRAY_COUNT(NewProp_GrippingController_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripInformation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GrippingController,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Event triggered on the interfaced object when gripped" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnGrip", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420C00, sizeof(GrippableActor_eventOnGrip_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnGripRelease()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_bWasSocketed_SetBit = [](void* Obj){ ((GrippableActor_eventOnGripRelease_Parms*)Obj)->bWasSocketed = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bWasSocketed = { UE4CodeGen_Private::EPropertyClass::Bool, "bWasSocketed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventOnGripRelease_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bWasSocketed_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GripInformation_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GripInformation = { UE4CodeGen_Private::EPropertyClass::Struct, "GripInformation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnGripRelease_Parms, GripInformation), Z_Construct_UScriptStruct_FBPActorGripInformation, METADATA_PARAMS(NewProp_GripInformation_MetaData, ARRAY_COUNT(NewProp_GripInformation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReleasingController_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReleasingController = { UE4CodeGen_Private::EPropertyClass::Object, "ReleasingController", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnGripRelease_Parms, ReleasingController), Z_Construct_UClass_UGripMotionControllerComponent_NoRegister, METADATA_PARAMS(NewProp_ReleasingController_MetaData, ARRAY_COUNT(NewProp_ReleasingController_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bWasSocketed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripInformation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReleasingController,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Event triggered on the interfaced object when grip is released" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnGripRelease", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420C00, sizeof(GrippableActor_eventOnGripRelease_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_KeyEvent = { UE4CodeGen_Private::EPropertyClass::Byte, "KeyEvent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnInput_Parms, KeyEvent), Z_Construct_UEnum_Engine_EInputEvent, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_Key = { UE4CodeGen_Private::EPropertyClass::Struct, "Key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnInput_Parms, Key), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_KeyEvent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Key,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Call to send an action event to the object" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnInput", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventOnInput_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnSecondaryGrip()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GripInformation_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GripInformation = { UE4CodeGen_Private::EPropertyClass::Struct, "GripInformation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnSecondaryGrip_Parms, GripInformation), Z_Construct_UScriptStruct_FBPActorGripInformation, METADATA_PARAMS(NewProp_GripInformation_MetaData, ARRAY_COUNT(NewProp_GripInformation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SecondaryGripComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SecondaryGripComponent = { UE4CodeGen_Private::EPropertyClass::Object, "SecondaryGripComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnSecondaryGrip_Parms, SecondaryGripComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(NewProp_SecondaryGripComponent_MetaData, ARRAY_COUNT(NewProp_SecondaryGripComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripInformation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SecondaryGripComponent,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Event triggered on the interfaced object when secondary gripped" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnSecondaryGrip", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420C00, sizeof(GrippableActor_eventOnSecondaryGrip_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnSecondaryGripRelease()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GripInformation_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GripInformation = { UE4CodeGen_Private::EPropertyClass::Struct, "GripInformation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnSecondaryGripRelease_Parms, GripInformation), Z_Construct_UScriptStruct_FBPActorGripInformation, METADATA_PARAMS(NewProp_GripInformation_MetaData, ARRAY_COUNT(NewProp_GripInformation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReleasingSecondaryGripComponent_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReleasingSecondaryGripComponent = { UE4CodeGen_Private::EPropertyClass::Object, "ReleasingSecondaryGripComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventOnSecondaryGripRelease_Parms, ReleasingSecondaryGripComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(NewProp_ReleasingSecondaryGripComponent_MetaData, ARRAY_COUNT(NewProp_ReleasingSecondaryGripComponent_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripInformation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReleasingSecondaryGripComponent,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Event triggered on the interfaced object when secondary grip is released" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnSecondaryGripRelease", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420C00, sizeof(GrippableActor_eventOnSecondaryGripRelease_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnSecondaryUsed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Call to use an object" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnSecondaryUsed", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_OnUsed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Call to use an object" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "OnUsed", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_RequestsSocketing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((GrippableActor_eventRequestsSocketing_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventRequestsSocketing_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_RelativeTransform = { UE4CodeGen_Private::EPropertyClass::Struct, "RelativeTransform", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventRequestsSocketing_Parms, RelativeTransform), Z_Construct_UScriptStruct_FTransform_NetQuantize, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FNamePropertyParams NewProp_OptionalSocketName = { UE4CodeGen_Private::EPropertyClass::Name, "OptionalSocketName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventRequestsSocketing_Parms, OptionalSocketName), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentToSocketTo_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParentToSocketTo = { UE4CodeGen_Private::EPropertyClass::Object, "ParentToSocketTo", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080180, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventRequestsSocketing_Parms, ParentToSocketTo), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(NewProp_ParentToSocketTo_MetaData, ARRAY_COUNT(NewProp_ParentToSocketTo_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RelativeTransform,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OptionalSocketName,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ParentToSocketTo,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Returns if the object is socketed currently" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "RequestsSocketing", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C420C00, sizeof(GrippableActor_eventRequestsSocketing_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_SecondaryGripType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Enum, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventSecondaryGripType_Parms, ReturnValue), Z_Construct_UEnum_VRExpansionPlugin_ESecondaryGripType, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Secondary grip type" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "SecondaryGripType", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventSecondaryGripType_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_SetHeld()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_bIsHeld_SetBit = [](void* Obj){ ((GrippableActor_eventSetHeld_Parms*)Obj)->bIsHeld = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsHeld = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsHeld", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventSetHeld_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bIsHeld_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HoldingController_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HoldingController = { UE4CodeGen_Private::EPropertyClass::Object, "HoldingController", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventSetHeld_Parms, HoldingController), Z_Construct_UClass_UGripMotionControllerComponent_NoRegister, METADATA_PARAMS(NewProp_HoldingController_MetaData, ARRAY_COUNT(NewProp_HoldingController_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bIsHeld,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HoldingController,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Sets is held, used by the plugin" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "SetHeld", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventSetHeld_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_SimulateOnDrop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((GrippableActor_eventSimulateOnDrop_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrippableActor_eventSimulateOnDrop_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Should this object simulate on drop" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "SimulateOnDrop", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventSimulateOnDrop_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_TeleportBehavior()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Enum, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventTeleportBehavior_Parms, ReturnValue), Z_Construct_UEnum_VRExpansionPlugin_EGripInterfaceTeleportBehavior, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying = { UE4CodeGen_Private::EPropertyClass::Byte, "UnderlyingType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Underlying,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "How an interfaced object behaves when teleporting" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "TeleportBehavior", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, sizeof(GrippableActor_eventTeleportBehavior_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AGrippableActor_TickGrip()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime = { UE4CodeGen_Private::EPropertyClass::Float, "DeltaTime", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventTickGrip_Parms, DeltaTime), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GripInformation_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GripInformation = { UE4CodeGen_Private::EPropertyClass::Struct, "GripInformation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008008000182, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventTickGrip_Parms, GripInformation), Z_Construct_UScriptStruct_FBPActorGripInformation, METADATA_PARAMS(NewProp_GripInformation_MetaData, ARRAY_COUNT(NewProp_GripInformation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GrippingController_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GrippingController = { UE4CodeGen_Private::EPropertyClass::Object, "GrippingController", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(GrippableActor_eventTickGrip_Parms, GrippingController), Z_Construct_UClass_UGripMotionControllerComponent_NoRegister, METADATA_PARAMS(NewProp_GrippingController_MetaData, ARRAY_COUNT(NewProp_GrippingController_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DeltaTime,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GripInformation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GrippingController,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Event triggered each tick on the interfaced object when gripped, can be used for custom movement or grip based logic" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrippableActor, "TickGrip", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08420C00, sizeof(GrippableActor_eventTickGrip_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGrippableActor_NoRegister()
	{
		return AGrippableActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AGrippableActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_VRExpansionPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AGrippableActor_AdvancedGripSettings, "AdvancedGripSettings" }, // 579267267
				{ &Z_Construct_UFunction_AGrippableActor_ClosestGripSlotInRange, "ClosestGripSlotInRange" }, // 1293746489
				{ &Z_Construct_UFunction_AGrippableActor_DenyGripping, "DenyGripping" }, // 2433096131
				{ &Z_Construct_UFunction_AGrippableActor_GetGripStiffnessAndDamping, "GetGripStiffnessAndDamping" }, // 785808292
				{ &Z_Construct_UFunction_AGrippableActor_GetInteractionSettings, "GetInteractionSettings" }, // 1035336424
				{ &Z_Construct_UFunction_AGrippableActor_GetPrimaryGripType, "GetPrimaryGripType" }, // 66689849
				{ &Z_Construct_UFunction_AGrippableActor_GripBreakDistance, "GripBreakDistance" }, // 565278501
				{ &Z_Construct_UFunction_AGrippableActor_GripLateUpdateSetting, "GripLateUpdateSetting" }, // 1522854133
				{ &Z_Construct_UFunction_AGrippableActor_GripMovementReplicationType, "GripMovementReplicationType" }, // 1806171874
				{ &Z_Construct_UFunction_AGrippableActor_IsHeld, "IsHeld" }, // 590566192
				{ &Z_Construct_UFunction_AGrippableActor_IsInteractible, "IsInteractible" }, // 1251596079
				{ &Z_Construct_UFunction_AGrippableActor_OnChildGrip, "OnChildGrip" }, // 3358040496
				{ &Z_Construct_UFunction_AGrippableActor_OnChildGripRelease, "OnChildGripRelease" }, // 1899239307
				{ &Z_Construct_UFunction_AGrippableActor_OnEndSecondaryUsed, "OnEndSecondaryUsed" }, // 1029928430
				{ &Z_Construct_UFunction_AGrippableActor_OnEndUsed, "OnEndUsed" }, // 2475803014
				{ &Z_Construct_UFunction_AGrippableActor_OnGrip, "OnGrip" }, // 2565951824
				{ &Z_Construct_UFunction_AGrippableActor_OnGripRelease, "OnGripRelease" }, // 2184769258
				{ &Z_Construct_UFunction_AGrippableActor_OnInput, "OnInput" }, // 2793964538
				{ &Z_Construct_UFunction_AGrippableActor_OnSecondaryGrip, "OnSecondaryGrip" }, // 3540507330
				{ &Z_Construct_UFunction_AGrippableActor_OnSecondaryGripRelease, "OnSecondaryGripRelease" }, // 3192030652
				{ &Z_Construct_UFunction_AGrippableActor_OnSecondaryUsed, "OnSecondaryUsed" }, // 4227984584
				{ &Z_Construct_UFunction_AGrippableActor_OnUsed, "OnUsed" }, // 3928192418
				{ &Z_Construct_UFunction_AGrippableActor_RequestsSocketing, "RequestsSocketing" }, // 934947388
				{ &Z_Construct_UFunction_AGrippableActor_SecondaryGripType, "SecondaryGripType" }, // 2824045715
				{ &Z_Construct_UFunction_AGrippableActor_SetHeld, "SetHeld" }, // 3899263707
				{ &Z_Construct_UFunction_AGrippableActor_SimulateOnDrop, "SimulateOnDrop" }, // 793887189
				{ &Z_Construct_UFunction_AGrippableActor_TeleportBehavior, "TeleportBehavior" }, // 103040607
				{ &Z_Construct_UFunction_AGrippableActor_TickGrip, "TickGrip" }, // 447546194
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "BlueprintType", "true" },
				{ "ClassGroupNames", "VRExpansionPlugin" },
				{ "IncludePath", "Grippables/GrippableActor.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VRGripInterfaceSettings_MetaData[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_VRGripInterfaceSettings = { UE4CodeGen_Private::EPropertyClass::Struct, "VRGripInterfaceSettings", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010008000000025, 1, nullptr, STRUCT_OFFSET(AGrippableActor, VRGripInterfaceSettings), Z_Construct_UScriptStruct_FBPInterfaceProperties, METADATA_PARAMS(NewProp_VRGripInterfaceSettings_MetaData, ARRAY_COUNT(NewProp_VRGripInterfaceSettings_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bRepGripSettingsAndGameplayTags_MetaData[] = {
				{ "Category", "VRGripInterface" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
			};
#endif
			auto NewProp_bRepGripSettingsAndGameplayTags_SetBit = [](void* Obj){ ((AGrippableActor*)Obj)->bRepGripSettingsAndGameplayTags = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bRepGripSettingsAndGameplayTags = { UE4CodeGen_Private::EPropertyClass::Bool, "bRepGripSettingsAndGameplayTags", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000025, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AGrippableActor), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bRepGripSettingsAndGameplayTags_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bRepGripSettingsAndGameplayTags_MetaData, ARRAY_COUNT(NewProp_bRepGripSettingsAndGameplayTags_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bAllowIgnoringAttachOnOwner_MetaData[] = {
				{ "Category", "Replication" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Skips the attachment replication if we are locally owned and our grip settings say that we are a client authed grip." },
			};
#endif
			auto NewProp_bAllowIgnoringAttachOnOwner_SetBit = [](void* Obj){ ((AGrippableActor*)Obj)->bAllowIgnoringAttachOnOwner = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bAllowIgnoringAttachOnOwner = { UE4CodeGen_Private::EPropertyClass::Bool, "bAllowIgnoringAttachOnOwner", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000025, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(AGrippableActor), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bAllowIgnoringAttachOnOwner_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bAllowIgnoringAttachOnOwner_MetaData, ARRAY_COUNT(NewProp_bAllowIgnoringAttachOnOwner_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameplayTags_MetaData[] = {
				{ "Category", "GameplayTags" },
				{ "ModuleRelativePath", "Public/Grippables/GrippableActor.h" },
				{ "ToolTip", "Tags that are set on this object" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_GameplayTags = { UE4CodeGen_Private::EPropertyClass::Struct, "GameplayTags", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000025, 1, nullptr, STRUCT_OFFSET(AGrippableActor, GameplayTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(NewProp_GameplayTags_MetaData, ARRAY_COUNT(NewProp_GameplayTags_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_VRGripInterfaceSettings,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bRepGripSettingsAndGameplayTags,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bAllowIgnoringAttachOnOwner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GameplayTags,
			};
			static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[] = {
				{ Z_Construct_UClass_UVRGripInterface_NoRegister, (int32)VTABLE_OFFSET(AGrippableActor, IVRGripInterface), false },
				{ Z_Construct_UClass_UGameplayTagAssetInterface_NoRegister, (int32)VTABLE_OFFSET(AGrippableActor, IGameplayTagAssetInterface), false },
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AGrippableActor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AGrippableActor::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				InterfaceParams, ARRAY_COUNT(InterfaceParams),
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGrippableActor, 4215864643);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGrippableActor(Z_Construct_UClass_AGrippableActor, &AGrippableActor::StaticClass, TEXT("/Script/VRExpansionPlugin"), TEXT("AGrippableActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGrippableActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
