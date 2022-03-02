// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AlienEscape/AlienEscapePlatform.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAlienEscapePlatform() {}
// Cross Module References
	ALIENESCAPE_API UClass* Z_Construct_UClass_AAlienEscapePlatform_NoRegister();
	ALIENESCAPE_API UClass* Z_Construct_UClass_AAlienEscapePlatform();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_AlienEscape();
// End Cross Module References
	void AAlienEscapePlatform::StaticRegisterNativesAAlienEscapePlatform()
	{
	}
	UClass* Z_Construct_UClass_AAlienEscapePlatform_NoRegister()
	{
		return AAlienEscapePlatform::StaticClass();
	}
	struct Z_Construct_UClass_AAlienEscapePlatform_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAlienEscapePlatform_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_AlienEscape,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapePlatform_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "AlienEscapePlatform.h" },
		{ "ModuleRelativePath", "AlienEscapePlatform.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAlienEscapePlatform_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAlienEscapePlatform>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAlienEscapePlatform_Statics::ClassParams = {
		&AAlienEscapePlatform::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAlienEscapePlatform_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapePlatform_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAlienEscapePlatform()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAlienEscapePlatform_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAlienEscapePlatform, 360602498);
	template<> ALIENESCAPE_API UClass* StaticClass<AAlienEscapePlatform>()
	{
		return AAlienEscapePlatform::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAlienEscapePlatform(Z_Construct_UClass_AAlienEscapePlatform, &AAlienEscapePlatform::StaticClass, TEXT("/Script/AlienEscape"), TEXT("AAlienEscapePlatform"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAlienEscapePlatform);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
