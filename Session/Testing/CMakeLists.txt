GViS_add_test(TestReflectionGadgetToVariantMap GViS::Session GViS::Common)
GViS_add_test(TestReflectionObjectSerialize GViS::Session GViS::Common)

target_sources(TestReflectionGadgetToVariantMap PRIVATE
    TestGadgets.h
)

target_sources(TestReflectionObjectSerialize PRIVATE
    TestQObjects.h
)