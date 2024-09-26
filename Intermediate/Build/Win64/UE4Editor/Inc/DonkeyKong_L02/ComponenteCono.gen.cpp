// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DonkeyKong_L02/ComponenteCono.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeComponenteCono() {}
// Cross Module References
	DONKEYKONG_L02_API UClass* Z_Construct_UClass_AComponenteCono_NoRegister();
	DONKEYKONG_L02_API UClass* Z_Construct_UClass_AComponenteCono();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_DonkeyKong_L02();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AComponenteCono::StaticRegisterNativesAComponenteCono()
	{
	}
	UClass* Z_Construct_UClass_AComponenteCono_NoRegister()
	{
		return AComponenteCono::StaticClass();
	}
	struct Z_Construct_UClass_AComponenteCono_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ConoMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ConoMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AComponenteCono_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_DonkeyKong_L02,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponenteCono_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ComponenteCono.h" },
		{ "ModuleRelativePath", "ComponenteCono.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AComponenteCono_Statics::NewProp_ConoMesh_MetaData[] = {
		{ "Category", "ComponenteCono" },
		{ "Comment", "// Malla para representar el cono visualmente\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ComponenteCono.h" },
		{ "ToolTip", "Malla para representar el cono visualmente" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AComponenteCono_Statics::NewProp_ConoMesh = { "ConoMesh", nullptr, (EPropertyFlags)0x00400000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AComponenteCono, ConoMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AComponenteCono_Statics::NewProp_ConoMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteCono_Statics::NewProp_ConoMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AComponenteCono_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AComponenteCono_Statics::NewProp_ConoMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AComponenteCono_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AComponenteCono>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AComponenteCono_Statics::ClassParams = {
		&AComponenteCono::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AComponenteCono_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteCono_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AComponenteCono_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AComponenteCono_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AComponenteCono()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AComponenteCono_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AComponenteCono, 955529426);
	template<> DONKEYKONG_L02_API UClass* StaticClass<AComponenteCono>()
	{
		return AComponenteCono::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AComponenteCono(Z_Construct_UClass_AComponenteCono, &AComponenteCono::StaticClass, TEXT("/Script/DonkeyKong_L02"), TEXT("AComponenteCono"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AComponenteCono);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
