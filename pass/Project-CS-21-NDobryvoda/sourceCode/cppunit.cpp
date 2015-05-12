#include "CompilerOutputter.h"
#include "TestFactoryRegistry.h"
#include "TestRunner.h"
#include "HelperMacros.h"

#include "parser.h"

class testParser : public CppUnit::TestCase {
	public:
	string input;
	string expectedOutput;
	testParser(string in, string out){
		input = in;
		expectedOutput = out;
	}
	 void runTest(){
	
		string output = Parser::GetName(output);
		CPPUNIT_ASSERT( output == expectedOutput);
	 };
};


int main()
{

	string input1 = "5Branets Roman 91, 85, 87, 83, 69, 79, 81, 78, 84, 93";
	string output1 = "1 75.9091";
	string input2 = "Verbyнеtska Valeriia 78, 83, 85, 75, 91, 88, 79, 85, 83, 90";
	string output2 = "2 Verby 83.7";
	
	testParser test1(input1, output1);
	testParser test2(input2, output2);
	
	CppUnit::TextTestRunner runner;
	runner.addTest(&test1);
	runner.addTest(&test2);
	runner.run();
	
	return 0;
}
