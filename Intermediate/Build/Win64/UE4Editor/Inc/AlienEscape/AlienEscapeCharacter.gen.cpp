// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AlienEscape/AlienEscapeCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAlienEscapeCharacter() {}
// Cross Module References
	ALIENESCAPE_API UClass* Z_Construct_UClass_AAlienEscapeCharacter_NoRegister();
	ALIENESCAPE_API UClass* Z_Construct_UClass_AAlienEscapeCharacter();
	PAPER2D_API UClass* Z_Construct_UClass_APaperCharacter();
	UPackage* Z_Construct_UPackage__Script_AlienEscape();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	PAPER2D_API UClass* Z_Construct_UClass_UPaperFlipbook_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	void AAlienEscapeCharacter::StaticRegisterNativesAAlienEscapeCharacter()
	{
	}
	UClass* Z_Construct_UClass_AAlienEscapeCharacter_NoRegister()
	{
		return AAlienEscapeCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AAlienEscapeCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SideViewCameraComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SideViewCameraComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringPlatformBottom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringPlatformBottom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringPlatformMiddle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringPlatformMiddle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpringPlatformTop_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpringPlatformTop;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RunningAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RunningAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IdleAnimation_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_IdleAnimation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlatformSpawnerBottom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlatformSpawnerBottom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlatformSpawnerMiddle_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlatformSpawnerMiddle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlatformSpawnerTop_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlatformSpawnerTop;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bottomPlatformSpawnerZ_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_bottomPlatformSpawnerZ;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_middlePlatformSpawnerZ_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_middlePlatformSpawnerZ;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_topPlatformSpawnerZ_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_topPlatformSpawnerZ;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AAlienEscapeCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APaperCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_AlienEscape,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * This class is the default character for AlienEscape, and it is responsible for all\n * physical interaction between the player and the world.\n *\n * The capsule component (inherited from ACharacter) handles collision with the world\n * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule\n * The Sprite component (inherited from APaperCharacter) handles the visuals\n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "AlienEscapeCharacter.h" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
		{ "ToolTip", "This class is the default character for AlienEscape, and it is responsible for all\nphysical interaction between the player and the world.\n\nThe capsule component (inherited from ACharacter) handles collision with the world\nThe CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule\nThe Sprite component (inherited from APaperCharacter) handles the visuals" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SideViewCameraComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Side view camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
		{ "ToolTip", "Side view camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SideViewCameraComponent = { "SideViewCameraComponent", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, SideViewCameraComponent), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SideViewCameraComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SideViewCameraComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera beside the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera beside the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformBottom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawner" },
		{ "Comment", "/** Spring Arm for Spawners */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
		{ "ToolTip", "Spring Arm for Spawners" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformBottom = { "SpringPlatformBottom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, SpringPlatformBottom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformBottom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformBottom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformMiddle_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawner" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformMiddle = { "SpringPlatformMiddle", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, SpringPlatformMiddle), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformMiddle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformMiddle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformTop_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawner" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformTop = { "SpringPlatformTop", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, SpringPlatformTop), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformTop_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformTop_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_RunningAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while running around\n" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
		{ "ToolTip", "The animation to play while running around" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_RunningAnimation = { "RunningAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, RunningAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_RunningAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_RunningAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_IdleAnimation_MetaData[] = {
		{ "Category", "Animations" },
		{ "Comment", "// The animation to play while idle (standing still)\n" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
		{ "ToolTip", "The animation to play while idle (standing still)" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_IdleAnimation = { "IdleAnimation", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, IdleAnimation), Z_Construct_UClass_UPaperFlipbook_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_IdleAnimation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_IdleAnimation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerBottom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawner" },
		{ "Comment", "/** Spawner components */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
		{ "ToolTip", "Spawner components" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerBottom = { "PlatformSpawnerBottom", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, PlatformSpawnerBottom), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerBottom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerBottom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerMiddle_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawner" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerMiddle = { "PlatformSpawnerMiddle", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, PlatformSpawnerMiddle), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerMiddle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerMiddle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerTop_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Spawner" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerTop = { "PlatformSpawnerTop", nullptr, (EPropertyFlags)0x002008000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, PlatformSpawnerTop), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerTop_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerTop_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_bottomPlatformSpawnerZ_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_bottomPlatformSpawnerZ = { "bottomPlatformSpawnerZ", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, bottomPlatformSpawnerZ), METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_bottomPlatformSpawnerZ_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_bottomPlatformSpawnerZ_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_middlePlatformSpawnerZ_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_middlePlatformSpawnerZ = { "middlePlatformSpawnerZ", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, middlePlatformSpawnerZ), METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_middlePlatformSpawnerZ_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_middlePlatformSpawnerZ_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_topPlatformSpawnerZ_MetaData[] = {
		{ "Category", "Spawner" },
		{ "ModuleRelativePath", "AlienEscapeCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_topPlatformSpawnerZ = { "topPlatformSpawnerZ", nullptr, (EPropertyFlags)0x0020080000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AAlienEscapeCharacter, topPlatformSpawnerZ), METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_topPlatformSpawnerZ_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_topPlatformSpawnerZ_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AAlienEscapeCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SideViewCameraComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformBottom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformMiddle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_SpringPlatformTop,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_RunningAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_IdleAnimation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerBottom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerMiddle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_PlatformSpawnerTop,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_bottomPlatformSpawnerZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_middlePlatformSpawnerZ,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AAlienEscapeCharacter_Statics::NewProp_topPlatformSpawnerZ,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AAlienEscapeCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AAlienEscapeCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AAlienEscapeCharacter_Statics::ClassParams = {
		&AAlienEscapeCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AAlienEscapeCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AAlienEscapeCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AAlienEscapeCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AAlienEscapeCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AAlienEscapeCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AAlienEscapeCharacter, 241472236);
	template<> ALIENESCAPE_API UClass* StaticClass<AAlienEscapeCharacter>()
	{
		return AAlienEscapeCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AAlienEscapeCharacter(Z_Construct_UClass_AAlienEscapeCharacter, &AAlienEscapeCharacter::StaticClass, TEXT("/Script/AlienEscape"), TEXT("AAlienEscapeCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AAlienEscapeCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
