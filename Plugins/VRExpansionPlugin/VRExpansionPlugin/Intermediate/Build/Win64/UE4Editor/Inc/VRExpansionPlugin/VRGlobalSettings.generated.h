// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FBPVRControllerProfile;
struct FTransform;
#ifdef VREXPANSIONPLUGIN_VRGlobalSettings_generated_h
#error "VRGlobalSettings.generated.h already included, missing '#pragma once' in VRGlobalSettings.h"
#endif
#define VREXPANSIONPLUGIN_VRGlobalSettings_generated_h

#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_40_GENERATED_BODY \
	friend VREXPANSIONPLUGIN_API class UScriptStruct* Z_Construct_UScriptStruct_FBPVRControllerProfile(); \
	static class UScriptStruct* StaticStruct();


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_29_GENERATED_BODY \
	friend VREXPANSIONPLUGIN_API class UScriptStruct* Z_Construct_UScriptStruct_FActionMappingDetails(); \
	VREXPANSIONPLUGIN_API static class UScriptStruct* StaticStruct();


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_17_GENERATED_BODY \
	friend VREXPANSIONPLUGIN_API class UScriptStruct* Z_Construct_UScriptStruct_FAxisMappingDetails(); \
	VREXPANSIONPLUGIN_API static class UScriptStruct* StaticStruct();


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execLoadControllerProfile) \
	{ \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_ControllerProfile); \
		P_GET_UBOOL(Z_Param_bSetAsCurrentProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVRGlobalSettings::LoadControllerProfile(Z_Param_Out_ControllerProfile,Z_Param_bSetAsCurrentProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControllerProfileByName) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ControllerProfileName); \
		P_GET_UBOOL(Z_Param_bSetAsCurrentProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVRGlobalSettings::LoadControllerProfileByName(Z_Param_ControllerProfileName,Z_Param_bSetAsCurrentProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetControllerProfile) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ControllerProfileName); \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_OutProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVRGlobalSettings::GetControllerProfile(Z_Param_ControllerProfileName,Z_Param_Out_OutProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentProfile) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bHadLoadedProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FBPVRControllerProfile*)Z_Param__Result=UVRGlobalSettings::GetCurrentProfile(Z_Param_Out_bHadLoadedProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentProfileName) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bHadLoadedProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=UVRGlobalSettings::GetCurrentProfileName(Z_Param_Out_bHadLoadedProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControllerProfiles) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVRGlobalSettings::SaveControllerProfiles(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDeleteControllerProfile) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ControllerProfileName); \
		P_GET_UBOOL(Z_Param_bSaveOutToConfig); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVRGlobalSettings::DeleteControllerProfile(Z_Param_ControllerProfileName,Z_Param_bSaveOutToConfig); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddControllerProfile) \
	{ \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_NewProfile); \
		P_GET_UBOOL(Z_Param_bSaveOutToConfig); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVRGlobalSettings::AddControllerProfile(Z_Param_Out_NewProfile,Z_Param_bSaveOutToConfig); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOverwriteControllerProfile) \
	{ \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_OverwritingProfile); \
		P_GET_UBOOL(Z_Param_bSaveOutToConfig); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVRGlobalSettings::OverwriteControllerProfile(Z_Param_Out_OverwritingProfile,Z_Param_bSaveOutToConfig); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetControllerProfiles) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FBPVRControllerProfile>*)Z_Param__Result=UVRGlobalSettings::GetControllerProfiles(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustTransformByGivenControllerProfile) \
	{ \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_ControllerProfile); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_SocketTransform); \
		P_GET_UBOOL(Z_Param_bIsRightHand); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=UVRGlobalSettings::AdjustTransformByGivenControllerProfile(Z_Param_Out_ControllerProfile,Z_Param_Out_SocketTransform,Z_Param_bIsRightHand); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustTransformByControllerProfile) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_OptionalControllerProfileName); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_SocketTransform); \
		P_GET_UBOOL(Z_Param_bIsRightHand); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=UVRGlobalSettings::AdjustTransformByControllerProfile(Z_Param_OptionalControllerProfileName,Z_Param_Out_SocketTransform,Z_Param_bIsRightHand); \
		P_NATIVE_END; \
	}


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execLoadControllerProfile) \
	{ \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_ControllerProfile); \
		P_GET_UBOOL(Z_Param_bSetAsCurrentProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVRGlobalSettings::LoadControllerProfile(Z_Param_Out_ControllerProfile,Z_Param_bSetAsCurrentProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execLoadControllerProfileByName) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ControllerProfileName); \
		P_GET_UBOOL(Z_Param_bSetAsCurrentProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVRGlobalSettings::LoadControllerProfileByName(Z_Param_ControllerProfileName,Z_Param_bSetAsCurrentProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetControllerProfile) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ControllerProfileName); \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_OutProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UVRGlobalSettings::GetControllerProfile(Z_Param_ControllerProfileName,Z_Param_Out_OutProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentProfile) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bHadLoadedProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FBPVRControllerProfile*)Z_Param__Result=UVRGlobalSettings::GetCurrentProfile(Z_Param_Out_bHadLoadedProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetCurrentProfileName) \
	{ \
		P_GET_UBOOL_REF(Z_Param_Out_bHadLoadedProfile); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FName*)Z_Param__Result=UVRGlobalSettings::GetCurrentProfileName(Z_Param_Out_bHadLoadedProfile); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveControllerProfiles) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVRGlobalSettings::SaveControllerProfiles(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDeleteControllerProfile) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_ControllerProfileName); \
		P_GET_UBOOL(Z_Param_bSaveOutToConfig); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVRGlobalSettings::DeleteControllerProfile(Z_Param_ControllerProfileName,Z_Param_bSaveOutToConfig); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddControllerProfile) \
	{ \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_NewProfile); \
		P_GET_UBOOL(Z_Param_bSaveOutToConfig); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVRGlobalSettings::AddControllerProfile(Z_Param_Out_NewProfile,Z_Param_bSaveOutToConfig); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execOverwriteControllerProfile) \
	{ \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_OverwritingProfile); \
		P_GET_UBOOL(Z_Param_bSaveOutToConfig); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UVRGlobalSettings::OverwriteControllerProfile(Z_Param_Out_OverwritingProfile,Z_Param_bSaveOutToConfig); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetControllerProfiles) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FBPVRControllerProfile>*)Z_Param__Result=UVRGlobalSettings::GetControllerProfiles(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustTransformByGivenControllerProfile) \
	{ \
		P_GET_STRUCT_REF(FBPVRControllerProfile,Z_Param_Out_ControllerProfile); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_SocketTransform); \
		P_GET_UBOOL(Z_Param_bIsRightHand); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=UVRGlobalSettings::AdjustTransformByGivenControllerProfile(Z_Param_Out_ControllerProfile,Z_Param_Out_SocketTransform,Z_Param_bIsRightHand); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAdjustTransformByControllerProfile) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_OptionalControllerProfileName); \
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_SocketTransform); \
		P_GET_UBOOL(Z_Param_bIsRightHand); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FTransform*)Z_Param__Result=UVRGlobalSettings::AdjustTransformByControllerProfile(Z_Param_OptionalControllerProfileName,Z_Param_Out_SocketTransform,Z_Param_bIsRightHand); \
		P_NATIVE_END; \
	}


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVRGlobalSettings(); \
	friend VREXPANSIONPLUGIN_API class UClass* Z_Construct_UClass_UVRGlobalSettings(); \
public: \
	DECLARE_CLASS(UVRGlobalSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), 0, TEXT("/Script/VRExpansionPlugin"), NO_API) \
	DECLARE_SERIALIZER(UVRGlobalSettings) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_INCLASS \
private: \
	static void StaticRegisterNativesUVRGlobalSettings(); \
	friend VREXPANSIONPLUGIN_API class UClass* Z_Construct_UClass_UVRGlobalSettings(); \
public: \
	DECLARE_CLASS(UVRGlobalSettings, UObject, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), 0, TEXT("/Script/VRExpansionPlugin"), NO_API) \
	DECLARE_SERIALIZER(UVRGlobalSettings) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	static const TCHAR* StaticConfigName() {return TEXT("Engine");} \



#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVRGlobalSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVRGlobalSettings) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVRGlobalSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVRGlobalSettings); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVRGlobalSettings(UVRGlobalSettings&&); \
	NO_API UVRGlobalSettings(const UVRGlobalSettings&); \
public:


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVRGlobalSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVRGlobalSettings(UVRGlobalSettings&&); \
	NO_API UVRGlobalSettings(const UVRGlobalSettings&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVRGlobalSettings); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVRGlobalSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVRGlobalSettings)


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_PRIVATE_PROPERTY_OFFSET
#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_102_PROLOG
#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_PRIVATE_PROPERTY_OFFSET \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_RPC_WRAPPERS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_INCLASS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_PRIVATE_PROPERTY_OFFSET \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_RPC_WRAPPERS_NO_PURE_DECLS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_INCLASS_NO_PURE_DECLS \
	AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h_105_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class VRGlobalSettings."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID AlienBetrayal_Plugins_VRExpansionPlugin_VRExpansionPlugin_Source_VRExpansionPlugin_Public_VRGlobalSettings_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
