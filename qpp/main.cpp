
#include "general/read.h"
//#include "lexer/Lexer.h"
#include "parser/SyntaxTree.h"
#include "compiler.h"


using namespace std;


int main() {
	vector<Pair> token_values = execute_lex("program.qpp").getLex().dict_output;
	vector<vector<Pair>> expressions = getEachExpression(token_values);
	
	
	SyntaxTree* main_tree;
	for(int i = 0; i < expressions.size(); i++) {
		SyntaxTree* st = new SyntaxTree(expressions[i]);
		if(st->getRoot()->getTValue() == "main") {
			//*main_tree = *st;
			main_tree = st;
				
		}
	
	}

	Node* root = main_tree->getRoot();
	
	free_regs = {0,0,0,0,0,0};
	file << "[extern printh]";
	file << "section .text:\nglobal main\nmain:\n";
	


	for(int i = 0; i < main_tree->get_child_trees().size(); i++) { 
		compile(&(main_tree->get_child_trees()[i]));	
	}
	
	file << "add esp," << var_counter*4 << endl;	
	file << "ret";	

	return 0;



}
