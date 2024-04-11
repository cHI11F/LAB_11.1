#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_11.1/LAB_11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestReadFile)
		{
			// Arrange
			string filename = "test_file.txt";
			string expected_content = "123abc456def789";
			ofstream test_file(filename);
			test_file << expected_content;
			test_file.close();

			// Act
			string actual_content = read_file(filename);

			// Assert
			Assert::AreEqual(expected_content, actual_content);
		}

		TEST_METHOD(TestFilterNonDigitCharacters)
		{
			// Arrange
			string data = "123abc456def789";
			string expected_filtered_data = "123456789";

			// Act
			string actual_filtered_data = filter_non_digit_characters(data);

			// Assert
			Assert::AreEqual(expected_filtered_data, actual_filtered_data);
		}

		TEST_METHOD(TestWriteFile)
		{
			// Arrange
			string filename = "test_output_file.txt";
			string data = "123456789";

			// Act
			write_file(filename, data);

			// Assert
			ifstream file(filename);
			Assert::IsTrue(file.is_open());
			string file_content;
			getline(file, file_content);
			file.close();
			Assert::AreEqual(data, file_content);
		}
	};
}
