// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FTransform;
#ifdef VREXPANSIONPLUGIN_VRGripScriptBase_generated_h
#error "VRGripScriptBase.generated.h already included, missing '#pragma once' in VRGripScriptBase.h"
#endif
#define VREXPANSIONPLUGIN_VRGripScriptBase_generated_h

#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_RPC_WRAPPERS \
	virtual void GetWorldTransform_PostStep_Implementation(FTransform& WorldTransform); \
	virtual void GetWorldTransform_Override_Implementation(FTransform& WorldTransform); \
	virtual void GetWorldTransform_PreStep_Implementation(FTransform& WorldTransform); \
	virtual void BeginPlay_Implementation(); \
 \
	DECLARE_FUNCTION(execGetWorldTransform_PostStep) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_WorldTransform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetWorldTransform_PostStep_Implementation(Z_Param_Out_WorldTransform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWorldTransform_Override) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_WorldTransform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetWorldTransform_Override_Implementation(Z_Param_Out_WorldTransform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWorldTransform_PreStep) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_WorldTransform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetWorldTransform_PreStep_Implementation(Z_Param_Out_WorldTransform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginPlay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BeginPlay_Implementation(); \
		P_NATIVE_END; \
	}


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetWorldTransform_PostStep) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_WorldTransform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetWorldTransform_PostStep_Implementation(Z_Param_Out_WorldTransform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWorldTransform_Override) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_WorldTransform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetWorldTransform_Override_Implementation(Z_Param_Out_WorldTransform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetWorldTransform_PreStep) \
	{ \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_WorldTransform); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->GetWorldTransform_PreStep_Implementation(Z_Param_Out_WorldTransform); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBeginPlay) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BeginPlay_Implementation(); \
		P_NATIVE_END; \
	}


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_EVENT_PARMS \
	struct VRGripScriptBase_eventGetWorldTransform_Override_Parms \
	{ \
		FTransform WorldTransform; \
	}; \
	struct VRGripScriptBase_eventGetWorldTransform_PostStep_Parms \
	{ \
		FTransform WorldTransform; \
	}; \
	struct VRGripScriptBase_eventGetWorldTransform_PreStep_Parms \
	{ \
		FTransform WorldTransform; \
	};


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_CALLBACK_WRAPPERS
#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVRGripScriptBase(); \
	friend VREXPANSIONPLUGIN_API class UClass* Z_Construct_UClass_UVRGripScriptBase(); \
public: \
	DECLARE_CLASS(UVRGripScriptBase, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VRExpansionPlugin"), NO_API) \
	DECLARE_SERIALIZER(UVRGripScriptBase) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_INCLASS \
private: \
	static void StaticRegisterNativesUVRGripScriptBase(); \
	friend VREXPANSIONPLUGIN_API class UClass* Z_Construct_UClass_UVRGripScriptBase(); \
public: \
	DECLARE_CLASS(UVRGripScriptBase, UObject, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VRExpansionPlugin"), NO_API) \
	DECLARE_SERIALIZER(UVRGripScriptBase) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVRGripScriptBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVRGripScriptBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVRGripScriptBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVRGripScriptBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVRGripScriptBase(UVRGripScriptBase&&); \
	NO_API UVRGripScriptBase(const UVRGripScriptBase&); \
public:


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVRGripScriptBase(UVRGripScriptBase&&); \
	NO_API UVRGripScriptBase(const UVRGripScriptBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVRGripScriptBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVRGripScriptBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVRGripScriptBase)


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_PRIVATE_PROPERTY_OFFSET
#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_18_PROLOG \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_EVENT_PARMS


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_PRIVATE_PROPERTY_OFFSET \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_RPC_WRAPPERS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_CALLBACK_WRAPPERS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_INCLASS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_PRIVATE_PROPERTY_OFFSET \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_CALLBACK_WRAPPERS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_INCLASS_NO_PURE_DECLS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_GripScripts_VRGripScriptBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
