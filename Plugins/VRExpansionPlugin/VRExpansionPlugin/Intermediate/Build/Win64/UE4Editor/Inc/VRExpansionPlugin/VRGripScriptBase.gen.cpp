// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/GripScripts/VRGripScriptBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVRGripScriptBase() {}
// Cross Module References
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_UVRGripScriptBase_NoRegister();
	VREXPANSIONPLUGIN_API UClass* Z_Construct_UClass_UVRGripScriptBase();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_VRExpansionPlugin();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_UVRGripScriptBase_BeginPlay();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_Override();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_PostStep();
	VREXPANSIONPLUGIN_API UFunction* Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_PreStep();
// End Cross Module References
	static FName NAME_UVRGripScriptBase_BeginPlay = FName(TEXT("BeginPlay"));
	void UVRGripScriptBase::BeginPlay()
	{
		ProcessEvent(FindFunctionChecked(NAME_UVRGripScriptBase_BeginPlay),NULL);
	}
	static FName NAME_UVRGripScriptBase_GetWorldTransform_Override = FName(TEXT("GetWorldTransform_Override"));
	void UVRGripScriptBase::GetWorldTransform_Override(FTransform& WorldTransform)
	{
		VRGripScriptBase_eventGetWorldTransform_Override_Parms Parms;
		Parms.WorldTransform=WorldTransform;
		ProcessEvent(FindFunctionChecked(NAME_UVRGripScriptBase_GetWorldTransform_Override),&Parms);
		WorldTransform=Parms.WorldTransform;
	}
	static FName NAME_UVRGripScriptBase_GetWorldTransform_PostStep = FName(TEXT("GetWorldTransform_PostStep"));
	void UVRGripScriptBase::GetWorldTransform_PostStep(FTransform& WorldTransform)
	{
		VRGripScriptBase_eventGetWorldTransform_PostStep_Parms Parms;
		Parms.WorldTransform=WorldTransform;
		ProcessEvent(FindFunctionChecked(NAME_UVRGripScriptBase_GetWorldTransform_PostStep),&Parms);
		WorldTransform=Parms.WorldTransform;
	}
	static FName NAME_UVRGripScriptBase_GetWorldTransform_PreStep = FName(TEXT("GetWorldTransform_PreStep"));
	void UVRGripScriptBase::GetWorldTransform_PreStep(FTransform& WorldTransform)
	{
		VRGripScriptBase_eventGetWorldTransform_PreStep_Parms Parms;
		Parms.WorldTransform=WorldTransform;
		ProcessEvent(FindFunctionChecked(NAME_UVRGripScriptBase_GetWorldTransform_PreStep),&Parms);
		WorldTransform=Parms.WorldTransform;
	}
	void UVRGripScriptBase::StaticRegisterNativesUVRGripScriptBase()
	{
		UClass* Class = UVRGripScriptBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginPlay", &UVRGripScriptBase::execBeginPlay },
			{ "GetWorldTransform_Override", &UVRGripScriptBase::execGetWorldTransform_Override },
			{ "GetWorldTransform_PostStep", &UVRGripScriptBase::execGetWorldTransform_PostStep },
			{ "GetWorldTransform_PreStep", &UVRGripScriptBase::execGetWorldTransform_PreStep },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UVRGripScriptBase_BeginPlay()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripScript|Init" },
				{ "ModuleRelativePath", "Public/GripScripts/VRGripScriptBase.h" },
				{ "ToolTip", "Not all scripts will require this function, specific ones that use things like Lever logic however will. Best to call it." },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRGripScriptBase, "BeginPlay", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_Override()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorldTransform = { UE4CodeGen_Private::EPropertyClass::Struct, "WorldTransform", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VRGripScriptBase_eventGetWorldTransform_Override_Parms, WorldTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WorldTransform,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripScript|Steps" },
				{ "ModuleRelativePath", "Public/GripScripts/VRGripScriptBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRGripScriptBase, "GetWorldTransform_Override", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0CC20C00, sizeof(VRGripScriptBase_eventGetWorldTransform_Override_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_PostStep()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorldTransform = { UE4CodeGen_Private::EPropertyClass::Struct, "WorldTransform", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VRGripScriptBase_eventGetWorldTransform_PostStep_Parms, WorldTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WorldTransform,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripScript|Steps" },
				{ "ModuleRelativePath", "Public/GripScripts/VRGripScriptBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRGripScriptBase, "GetWorldTransform_PostStep", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0CC20C00, sizeof(VRGripScriptBase_eventGetWorldTransform_PostStep_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_PreStep()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_WorldTransform = { UE4CodeGen_Private::EPropertyClass::Struct, "WorldTransform", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(VRGripScriptBase_eventGetWorldTransform_PreStep_Parms, WorldTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_WorldTransform,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "VRGripScript|Steps" },
				{ "ModuleRelativePath", "Public/GripScripts/VRGripScriptBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVRGripScriptBase, "GetWorldTransform_PreStep", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0CC20C00, sizeof(VRGripScriptBase_eventGetWorldTransform_PreStep_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UVRGripScriptBase_NoRegister()
	{
		return UVRGripScriptBase::StaticClass();
	}
	UClass* Z_Construct_UClass_UVRGripScriptBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_VRExpansionPlugin,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UVRGripScriptBase_BeginPlay, "BeginPlay" }, // 2257846685
				{ &Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_Override, "GetWorldTransform_Override" }, // 1795307331
				{ &Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_PostStep, "GetWorldTransform_PostStep" }, // 1704897916
				{ &Z_Construct_UFunction_UVRGripScriptBase_GetWorldTransform_PreStep, "GetWorldTransform_PreStep" }, // 4250982382
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ClassGroupNames", "VRExpansionPlugin" },
				{ "IncludePath", "GripScripts/VRGripScriptBase.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/GripScripts/VRGripScriptBase.h" },
				{ "ObjectInitializerConstructorDeclared", "" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UVRGripScriptBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UVRGripScriptBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00301080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVRGripScriptBase, 3878690042);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVRGripScriptBase(Z_Construct_UClass_UVRGripScriptBase, &UVRGripScriptBase::StaticClass, TEXT("/Script/VRExpansionPlugin"), TEXT("UVRGripScriptBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVRGripScriptBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
