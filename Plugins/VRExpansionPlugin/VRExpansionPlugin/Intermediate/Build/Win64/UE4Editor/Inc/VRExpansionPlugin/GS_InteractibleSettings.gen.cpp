// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/GripScripts/GS_InteractibleSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGS_InteractibleSettings() {}
// Cross Module References
	VREXPANSIONPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FBPGS_InteractionSettings();
	UPackage* Z_Construct_UPackage__Script_VRExpansionPlugin();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FVector_NetQuantize100();
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_UGS_InteractibleSettings_NoRegister();
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_UGS_InteractibleSettings();
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_UVRGripScriptBase();
// End Cross Module References
class UScriptStruct* FBPGS_InteractionSettings::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern VREXPANSIONPLUGIN_API uint32 Get_Z_Construct_UScriptStruct_FBPGS_InteractionSettings_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FBPGS_InteractionSettings, Z_Construct_UPackage__Script_VRExpansionPlugin(), TEXT("BPGS_InteractionSettings"), sizeof(FBPGS_InteractionSettings), Get_Z_Construct_UScriptStruct_FBPGS_InteractionSettings_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FBPGS_InteractionSettings(FBPGS_InteractionSettings::StaticStruct, TEXT("/Script/VRExpansionPlugin"), TEXT("BPGS_InteractionSettings"), false, nullptr, nullptr);
static struct FScriptStruct_VRExpansionPlugin_StaticRegisterNativesFBPGS_InteractionSettings
{
	FScriptStruct_VRExpansionPlugin_StaticRegisterNativesFBPGS_InteractionSettings()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("BPGS_InteractionSettings")),new UScriptStruct::TCppStructOps<FBPGS_InteractionSettings>);
	}
} ScriptStruct_VRExpansionPlugin_StaticRegisterNativesFBPGS_InteractionSettings;
	UScriptStruct* Z_Construct_UScriptStruct_FBPGS_InteractionSettings()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FBPGS_InteractionSettings_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_VRExpansionPlugin();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("BPGS_InteractionSettings"), sizeof(FBPGS_InteractionSettings), Get_Z_Construct_UScriptStruct_FBPGS_InteractionSettings_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Category", "VRExpansionLibrary" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBPGS_InteractionSettings>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxAngularTranslation_MetaData[] = {
				{ "Category", "AngularSettings" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_MaxAngularTranslation = { UE4CodeGen_Private::EPropertyClass::Struct, "MaxAngularTranslation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FBPGS_InteractionSettings, MaxAngularTranslation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(NewProp_MaxAngularTranslation_MetaData, ARRAY_COUNT(NewProp_MaxAngularTranslation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinAngularTranslation_MetaData[] = {
				{ "Category", "AngularSettings" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_MinAngularTranslation = { UE4CodeGen_Private::EPropertyClass::Struct, "MinAngularTranslation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FBPGS_InteractionSettings, MinAngularTranslation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(NewProp_MinAngularTranslation_MetaData, ARRAY_COUNT(NewProp_MinAngularTranslation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialAngularTranslation_MetaData[] = {
				{ "Category", "Settings|Angular" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_InitialAngularTranslation = { UE4CodeGen_Private::EPropertyClass::Struct, "InitialAngularTranslation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FBPGS_InteractionSettings, InitialAngularTranslation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(NewProp_InitialAngularTranslation_MetaData, ARRAY_COUNT(NewProp_InitialAngularTranslation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxLinearTranslation_MetaData[] = {
				{ "Category", "Settings|Linear" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_MaxLinearTranslation = { UE4CodeGen_Private::EPropertyClass::Struct, "MaxLinearTranslation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FBPGS_InteractionSettings, MaxLinearTranslation), Z_Construct_UScriptStruct_FVector_NetQuantize100, METADATA_PARAMS(NewProp_MaxLinearTranslation_MetaData, ARRAY_COUNT(NewProp_MaxLinearTranslation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MinLinearTranslation_MetaData[] = {
				{ "Category", "Settings|Linear" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_MinLinearTranslation = { UE4CodeGen_Private::EPropertyClass::Struct, "MinLinearTranslation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FBPGS_InteractionSettings, MinLinearTranslation), Z_Construct_UScriptStruct_FVector_NetQuantize100, METADATA_PARAMS(NewProp_MinLinearTranslation_MetaData, ARRAY_COUNT(NewProp_MinLinearTranslation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InitialLinearTranslation_MetaData[] = {
				{ "Category", "Settings|Linear" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_InitialLinearTranslation = { UE4CodeGen_Private::EPropertyClass::Struct, "InitialLinearTranslation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FBPGS_InteractionSettings, InitialLinearTranslation), Z_Construct_UScriptStruct_FVector_NetQuantize100, METADATA_PARAMS(NewProp_InitialLinearTranslation_MetaData, ARRAY_COUNT(NewProp_InitialLinearTranslation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIgnoreHandRotation_MetaData[] = {
				{ "Category", "Settings|Angular" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewProp_bIgnoreHandRotation_SetBit = [](void* Obj){ ((FBPGS_InteractionSettings*)Obj)->bIgnoreHandRotation = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIgnoreHandRotation = { UE4CodeGen_Private::EPropertyClass::Bool, "bIgnoreHandRotation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(uint8), UE4CodeGen_Private::ENativeBool::NotNative, sizeof(FBPGS_InteractionSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bIgnoreHandRotation_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bIgnoreHandRotation_MetaData, ARRAY_COUNT(NewProp_bIgnoreHandRotation_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLimitRoll_MetaData[] = {
				{ "Category", "Settings|Angular" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewProp_bLimitRoll_SetBit = [](void* Obj){ ((FBPGS_InteractionSettings*)Obj)->bLimitRoll = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLimitRoll = { UE4CodeGen_Private::EPropertyClass::Bool, "bLimitRoll", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(uint8), UE4CodeGen_Private::ENativeBool::NotNative, sizeof(FBPGS_InteractionSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bLimitRoll_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bLimitRoll_MetaData, ARRAY_COUNT(NewProp_bLimitRoll_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLimitYaw_MetaData[] = {
				{ "Category", "Settings|Angular" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewProp_bLimitYaw_SetBit = [](void* Obj){ ((FBPGS_InteractionSettings*)Obj)->bLimitYaw = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLimitYaw = { UE4CodeGen_Private::EPropertyClass::Bool, "bLimitYaw", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(uint8), UE4CodeGen_Private::ENativeBool::NotNative, sizeof(FBPGS_InteractionSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bLimitYaw_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bLimitYaw_MetaData, ARRAY_COUNT(NewProp_bLimitYaw_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLimitPitch_MetaData[] = {
				{ "Category", "Settings|Angular" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewProp_bLimitPitch_SetBit = [](void* Obj){ ((FBPGS_InteractionSettings*)Obj)->bLimitPitch = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLimitPitch = { UE4CodeGen_Private::EPropertyClass::Bool, "bLimitPitch", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(uint8), UE4CodeGen_Private::ENativeBool::NotNative, sizeof(FBPGS_InteractionSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bLimitPitch_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bLimitPitch_MetaData, ARRAY_COUNT(NewProp_bLimitPitch_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLimitZ_MetaData[] = {
				{ "Category", "Settings|Linear" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewProp_bLimitZ_SetBit = [](void* Obj){ ((FBPGS_InteractionSettings*)Obj)->bLimitZ = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLimitZ = { UE4CodeGen_Private::EPropertyClass::Bool, "bLimitZ", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(uint8), UE4CodeGen_Private::ENativeBool::NotNative, sizeof(FBPGS_InteractionSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bLimitZ_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bLimitZ_MetaData, ARRAY_COUNT(NewProp_bLimitZ_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLimitY_MetaData[] = {
				{ "Category", "Settings|Linear" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewProp_bLimitY_SetBit = [](void* Obj){ ((FBPGS_InteractionSettings*)Obj)->bLimitY = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLimitY = { UE4CodeGen_Private::EPropertyClass::Bool, "bLimitY", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(uint8), UE4CodeGen_Private::ENativeBool::NotNative, sizeof(FBPGS_InteractionSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bLimitY_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bLimitY_MetaData, ARRAY_COUNT(NewProp_bLimitY_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLimitX_MetaData[] = {
				{ "Category", "Settings|Linear" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewProp_bLimitX_SetBit = [](void* Obj){ ((FBPGS_InteractionSettings*)Obj)->bLimitX = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLimitX = { UE4CodeGen_Private::EPropertyClass::Bool, "bLimitX", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(uint8), UE4CodeGen_Private::ENativeBool::NotNative, sizeof(FBPGS_InteractionSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bLimitX_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bLimitX_MetaData, ARRAY_COUNT(NewProp_bLimitX_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLimitsInLocalSpace_MetaData[] = {
				{ "Category", "Settings" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
			auto NewProp_bLimitsInLocalSpace_SetBit = [](void* Obj){ ((FBPGS_InteractionSettings*)Obj)->bLimitsInLocalSpace = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLimitsInLocalSpace = { UE4CodeGen_Private::EPropertyClass::Bool, "bLimitsInLocalSpace", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, sizeof(uint8), UE4CodeGen_Private::ENativeBool::NotNative, sizeof(FBPGS_InteractionSettings), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_bLimitsInLocalSpace_SetBit)>::SetBit, METADATA_PARAMS(NewProp_bLimitsInLocalSpace_MetaData, ARRAY_COUNT(NewProp_bLimitsInLocalSpace_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaxAngularTranslation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MinAngularTranslation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InitialAngularTranslation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MaxLinearTranslation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_MinLinearTranslation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InitialLinearTranslation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bIgnoreHandRotation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bLimitRoll,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bLimitYaw,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bLimitPitch,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bLimitZ,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bLimitY,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bLimitX,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_bLimitsInLocalSpace,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_VRExpansionPlugin,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"BPGS_InteractionSettings",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000201),
				sizeof(FBPGS_InteractionSettings),
				alignof(FBPGS_InteractionSettings),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FBPGS_InteractionSettings_CRC() { return 666880409U; }
	void UGS_InteractibleSettings::StaticRegisterNativesUGS_InteractibleSettings()
	{
	}
	UClass* Z_Construct_UClass_UGS_InteractibleSettings_NoRegister()
	{
		return UGS_InteractibleSettings::StaticClass();
	}
	UClass* Z_Construct_UClass_UGS_InteractibleSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UVRGripScriptBase,
				(UObject* (*)())Z_Construct_UPackage__Script_VRExpansionPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ClassGroupNames", "VRExpansionPlugin" },
				{ "IncludePath", "GripScripts/GS_InteractibleSettings.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InteractionSettings_MetaData[] = {
				{ "Category", "GS_InteractibleSettings" },
				{ "ModuleRelativePath", "Public/GripScripts/GS_InteractibleSettings.h" },
				{ "ToolTip", "Useful functions to override in c++ for functionality\nvirtual void BeginPlay() override;\nvirtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);\nCategory = \"InteractionSettings\")" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_InteractionSettings = { UE4CodeGen_Private::EPropertyClass::Struct, "InteractionSettings", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UGS_InteractibleSettings, InteractionSettings), Z_Construct_UScriptStruct_FBPGS_InteractionSettings, METADATA_PARAMS(NewProp_InteractionSettings_MetaData, ARRAY_COUNT(NewProp_InteractionSettings_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_InteractionSettings,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UGS_InteractibleSettings>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UGS_InteractibleSettings::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00301080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGS_InteractibleSettings, 2043304651);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGS_InteractibleSettings(Z_Construct_UClass_UGS_InteractibleSettings, &UGS_InteractibleSettings::StaticClass, TEXT("/Script/VRExpansionPlugin"), TEXT("UGS_InteractibleSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGS_InteractibleSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
