#include "stdafx.h"
#include "GenericTypeReader.h"


void GenericTypeReader::Specialize(wstring const& targetType, wstring const& readerName, vector<wstring> const& genericArguments)
{
    this->targetType = targetType;
    this->readerName = readerName;
    this->genericArguments = genericArguments;
}


GenericTypeReader* GenericTypeReaderFactory::CreateTypeReader(vector<wstring> const& genericArguments)
{
    // Build up a .NET format generic type name suffix, eg. "Foo`2[[ArgType1],[ArgType2]]".
    wchar_t genericArgumentCount[16];

    swprintf(genericArgumentCount, ARRAY_SIZE(genericArgumentCount), L"`%d[[", genericArguments.size());

    wstring genericSuffix = genericArgumentCount;

    for (vector<wstring>::const_iterator iter = genericArguments.begin(); iter != genericArguments.end(); iter++)
    {
    	wstring const& genericArgument = *iter;
    	
        genericSuffix += genericArgument;

        if (&genericArgument != &genericArguments.back())
        {
            genericSuffix += L"],[";
        }
    }

    genericSuffix += L"]]";

    wstring targetType = GenericTargetType() + genericSuffix;
    wstring readerName = GenericReaderName() + genericSuffix;

    // Create and specialize the reader instance.
    GenericTypeReader* reader = CreateTypeReader();

    reader->Specialize(targetType, readerName, genericArguments);

    return reader;
}
