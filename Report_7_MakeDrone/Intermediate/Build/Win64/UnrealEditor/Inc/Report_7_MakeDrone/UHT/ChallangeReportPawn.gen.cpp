// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Report_7_MakeDrone/Public/ChallangeReportPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChallangeReportPawn() {}

// Begin Cross Module References
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
REPORT_7_MAKEDRONE_API UClass* Z_Construct_UClass_AChallangeReportPawn();
REPORT_7_MAKEDRONE_API UClass* Z_Construct_UClass_AChallangeReportPawn_NoRegister();
REPORT_7_MAKEDRONE_API UClass* Z_Construct_UClass_AReportPawn();
UPackage* Z_Construct_UPackage__Script_Report_7_MakeDrone();
// End Cross Module References

// Begin Class AChallangeReportPawn
void AChallangeReportPawn::StaticRegisterNativesAChallangeReportPawn()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AChallangeReportPawn);
UClass* Z_Construct_UClass_AChallangeReportPawn_NoRegister()
{
	return AChallangeReportPawn::StaticClass();
}
struct Z_Construct_UClass_AChallangeReportPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ChallangeReportPawn.h" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpAction_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DownAction_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotateLeftAction_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotateRightAction_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlightChangeAction_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gravity_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VerticalVelocity_MetaData[] = {
		{ "Category", "ChallangePawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd, \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd)\n" },
#endif
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xd3\xb5\xef\xbf\xbd (\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd, \xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd\xef\xbf\xbd \xef\xbf\xbd\xef\xbf\xbd)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_isJumpEnd_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_isLanding_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpTargetPoint_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlightMode_MetaData[] = {
		{ "Category", "ChallangePawn" },
		{ "ModuleRelativePath", "Public/ChallangeReportPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DownAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RotateLeftAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RotateRightAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_FlightChangeAction;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Gravity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VerticalVelocity;
	static void NewProp_isJumpEnd_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isJumpEnd;
	static void NewProp_isLanding_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_isLanding;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_JumpTargetPoint;
	static void NewProp_FlightMode_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_FlightMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChallangeReportPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_JumpAction = { "JumpAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChallangeReportPawn, JumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpAction_MetaData), NewProp_JumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_DownAction = { "DownAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChallangeReportPawn, DownAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DownAction_MetaData), NewProp_DownAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_RotateLeftAction = { "RotateLeftAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChallangeReportPawn, RotateLeftAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotateLeftAction_MetaData), NewProp_RotateLeftAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_RotateRightAction = { "RotateRightAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChallangeReportPawn, RotateRightAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotateRightAction_MetaData), NewProp_RotateRightAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_FlightChangeAction = { "FlightChangeAction", nullptr, (EPropertyFlags)0x0124080000000001, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChallangeReportPawn, FlightChangeAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlightChangeAction_MetaData), NewProp_FlightChangeAction_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChallangeReportPawn, Gravity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gravity_MetaData), NewProp_Gravity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_VerticalVelocity = { "VerticalVelocity", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChallangeReportPawn, VerticalVelocity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VerticalVelocity_MetaData), NewProp_VerticalVelocity_MetaData) };
void Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_isJumpEnd_SetBit(void* Obj)
{
	((AChallangeReportPawn*)Obj)->isJumpEnd = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_isJumpEnd = { "isJumpEnd", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AChallangeReportPawn), &Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_isJumpEnd_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_isJumpEnd_MetaData), NewProp_isJumpEnd_MetaData) };
void Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_isLanding_SetBit(void* Obj)
{
	((AChallangeReportPawn*)Obj)->isLanding = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_isLanding = { "isLanding", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AChallangeReportPawn), &Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_isLanding_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_isLanding_MetaData), NewProp_isLanding_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_JumpTargetPoint = { "JumpTargetPoint", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AChallangeReportPawn, JumpTargetPoint), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpTargetPoint_MetaData), NewProp_JumpTargetPoint_MetaData) };
void Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_FlightMode_SetBit(void* Obj)
{
	((AChallangeReportPawn*)Obj)->FlightMode = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_FlightMode = { "FlightMode", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AChallangeReportPawn), &Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_FlightMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlightMode_MetaData), NewProp_FlightMode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AChallangeReportPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_JumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_DownAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_RotateLeftAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_RotateRightAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_FlightChangeAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_Gravity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_VerticalVelocity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_isJumpEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_isLanding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_JumpTargetPoint,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AChallangeReportPawn_Statics::NewProp_FlightMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AChallangeReportPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AChallangeReportPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AReportPawn,
	(UObject* (*)())Z_Construct_UPackage__Script_Report_7_MakeDrone,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AChallangeReportPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AChallangeReportPawn_Statics::ClassParams = {
	&AChallangeReportPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AChallangeReportPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AChallangeReportPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AChallangeReportPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AChallangeReportPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AChallangeReportPawn()
{
	if (!Z_Registration_Info_UClass_AChallangeReportPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AChallangeReportPawn.OuterSingleton, Z_Construct_UClass_AChallangeReportPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AChallangeReportPawn.OuterSingleton;
}
template<> REPORT_7_MAKEDRONE_API UClass* StaticClass<AChallangeReportPawn>()
{
	return AChallangeReportPawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AChallangeReportPawn);
AChallangeReportPawn::~AChallangeReportPawn() {}
// End Class AChallangeReportPawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_Unreal_Project_git_Report_07_Report_7_MakeDrone_Source_Report_7_MakeDrone_Public_ChallangeReportPawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AChallangeReportPawn, AChallangeReportPawn::StaticClass, TEXT("AChallangeReportPawn"), &Z_Registration_Info_UClass_AChallangeReportPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AChallangeReportPawn), 3784084346U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Unreal_Project_git_Report_07_Report_7_MakeDrone_Source_Report_7_MakeDrone_Public_ChallangeReportPawn_h_2515700043(TEXT("/Script/Report_7_MakeDrone"),
	Z_CompiledInDeferFile_FID_Unreal_Project_git_Report_07_Report_7_MakeDrone_Source_Report_7_MakeDrone_Public_ChallangeReportPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Unreal_Project_git_Report_07_Report_7_MakeDrone_Source_Report_7_MakeDrone_Public_ChallangeReportPawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
