// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Report_7_MakeDrone/Public/ReportPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReportPawn() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
REPORT_7_MAKEDRONE_API UClass* Z_Construct_UClass_AReportPawn();
REPORT_7_MAKEDRONE_API UClass* Z_Construct_UClass_AReportPawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_Report_7_MakeDrone();
// End Cross Module References

// Begin Class AReportPawn
void AReportPawn::StaticRegisterNativesAReportPawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AReportPawn);
UClass* Z_Construct_UClass_AReportPawn_NoRegister()
{
	return AReportPawn::StaticClass();
}
struct Z_Construct_UClass_AReportPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ReportPawn.h" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapsuleComp_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ArrowComp_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CharMesh_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpringArmComp_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraComp_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[] = {
		{ "Category", "MyPawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xd4\xb7\xef\xbf\xbd\n" },
#endif
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xd4\xb7\xef\xbf\xbd" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinMoveSpeed_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NowMoveSpeed_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxMoveSpeed_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Acceleration_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpPower_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TurnSpeed_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraYaw_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraPitch_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraYawSpeed_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CameraPitchSpeed_MetaData[] = {
		{ "Category", "MyPawn" },
		{ "ModuleRelativePath", "Public/ReportPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CapsuleComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ArrowComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CharMesh;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpringArmComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CameraComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinMoveSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NowMoveSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxMoveSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Acceleration;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpPower;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TurnSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraYaw;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraPitch;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraYawSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_CameraPitchSpeed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AReportPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_CapsuleComp = { "CapsuleComp", nullptr, (EPropertyFlags)0x0124080000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, CapsuleComp), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapsuleComp_MetaData), NewProp_CapsuleComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_ArrowComp = { "ArrowComp", nullptr, (EPropertyFlags)0x0124080000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, ArrowComp), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ArrowComp_MetaData), NewProp_ArrowComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_CharMesh = { "CharMesh", nullptr, (EPropertyFlags)0x0124080000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, CharMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CharMesh_MetaData), NewProp_CharMesh_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_SpringArmComp = { "SpringArmComp", nullptr, (EPropertyFlags)0x0124080000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, SpringArmComp), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpringArmComp_MetaData), NewProp_SpringArmComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraComp = { "CameraComp", nullptr, (EPropertyFlags)0x0124080000080009, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, CameraComp), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraComp_MetaData), NewProp_CameraComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveAction_MetaData), NewProp_MoveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LookAction_MetaData), NewProp_LookAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_MinMoveSpeed = { "MinMoveSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, MinMoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinMoveSpeed_MetaData), NewProp_MinMoveSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_NowMoveSpeed = { "NowMoveSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, NowMoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NowMoveSpeed_MetaData), NewProp_NowMoveSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_MaxMoveSpeed = { "MaxMoveSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, MaxMoveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxMoveSpeed_MetaData), NewProp_MaxMoveSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_Acceleration = { "Acceleration", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, Acceleration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Acceleration_MetaData), NewProp_Acceleration_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_JumpPower = { "JumpPower", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, JumpPower), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpPower_MetaData), NewProp_JumpPower_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_TurnSpeed = { "TurnSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, TurnSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TurnSpeed_MetaData), NewProp_TurnSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraYaw = { "CameraYaw", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, CameraYaw), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraYaw_MetaData), NewProp_CameraYaw_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraPitch = { "CameraPitch", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, CameraPitch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraPitch_MetaData), NewProp_CameraPitch_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraYawSpeed = { "CameraYawSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, CameraYawSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraYawSpeed_MetaData), NewProp_CameraYawSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraPitchSpeed = { "CameraPitchSpeed", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AReportPawn, CameraPitchSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CameraPitchSpeed_MetaData), NewProp_CameraPitchSpeed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AReportPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_CapsuleComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_ArrowComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_CharMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_SpringArmComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_MoveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_LookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_MinMoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_NowMoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_MaxMoveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_Acceleration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_JumpPower,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_TurnSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraYaw,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraPitch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraYawSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReportPawn_Statics::NewProp_CameraPitchSpeed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AReportPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AReportPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Report_7_MakeDrone,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AReportPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AReportPawn_Statics::ClassParams = {
	&AReportPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AReportPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AReportPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AReportPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AReportPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AReportPawn()
{
	if (!Z_Registration_Info_UClass_AReportPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AReportPawn.OuterSingleton, Z_Construct_UClass_AReportPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AReportPawn.OuterSingleton;
}
template<> REPORT_7_MAKEDRONE_API UClass* StaticClass<AReportPawn>()
{
	return AReportPawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AReportPawn);
AReportPawn::~AReportPawn() {}
// End Class AReportPawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Project_git_Report_07_Report_7_MakeDrone_Source_Report_7_MakeDrone_Public_ReportPawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AReportPawn, AReportPawn::StaticClass, TEXT("AReportPawn"), &Z_Registration_Info_UClass_AReportPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AReportPawn), 3082192435U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_git_Report_07_Report_7_MakeDrone_Source_Report_7_MakeDrone_Public_ReportPawn_h_1468693381(TEXT("/Script/Report_7_MakeDrone"),
	Z_CompiledInDeferFile_FID_Unreal_Project_git_Report_07_Report_7_MakeDrone_Source_Report_7_MakeDrone_Public_ReportPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_git_Report_07_Report_7_MakeDrone_Source_Report_7_MakeDrone_Public_ReportPawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
