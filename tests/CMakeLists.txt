# Set the C++ standard.
set(CMAKE_CXX_STANDARD 20)

# Add source to the test's executable test.
add_executable(UnitTestStockPrvols "UnitTestStockPrvols.cpp"  )

# Specify libraries or flags to use when linking a given target and/or its dependents.
target_link_libraries(UnitTestStockPrvols PUBLIC StraightQuantStatic)

# Add a test to the project to be run by ctest.
add_test(
	NAME UnitTestStockPrvols
	COMMAND UnitTestStockPrvols
)

# Add source to the test's executable test.
add_executable(UnitTestStockTech "UnitTestStockTech.cpp"  )

# Specify libraries or flags to use when linking a given target and/or its dependents.
target_link_libraries(UnitTestStockTech PUBLIC StraightQuantStatic)

# Add a test to the project to be run by ctest.
add_test(
	NAME UnitTestStockTech
	COMMAND UnitTestStockTech
)

# Add source to the test's executable test.
add_executable(UnitTestStockProducts "UnitTestStockProducts.cpp"  )

# Specify libraries or flags to use when linking a given target and/or its dependents.
target_link_libraries(UnitTestStockProducts PUBLIC StraightQuantStatic)

# Add a test to the project to be run by ctest.
add_test(
	NAME UnitTestStockProducts
	COMMAND UnitTestStockProducts
)

# Add source to the test's executable test.
add_executable(UnitTestStockConstCharPtr "UnitTestStockConstCharPtr.cpp"  )

# Specify libraries or flags to use when linking a given target and/or its dependents.
target_link_libraries(UnitTestStockConstCharPtr PUBLIC StraightQuantStatic)

# Add a test to the project to be run by ctest.
add_test(
	NAME UnitTestStockConstCharPtr
	COMMAND UnitTestStockConstCharPtr
)