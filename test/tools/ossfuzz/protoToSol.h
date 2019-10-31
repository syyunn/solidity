/*
	This file is part of solidity.

	solidity is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	solidity is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with solidity.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <string>
#include <test/tools/ossfuzz/solProto.pb.h>

namespace dev
{
namespace test
{
namespace sol_fuzzer
{
class ProtoConverter
{
public:
	ProtoConverter() {}
	ProtoConverter(ProtoConverter const&) = delete;
	ProtoConverter(ProtoConverter&&) = delete;
	std::string protoToSolidity(Program const&);
private:
	std::string visit(Program const&);
	std::string visit(Block const&);
	std::string visit(Statement const&);
	std::string visit(VarDecl const&);
	std::string visit(IfStmt const&);
	std::string visit(ForStmt const&);
	std::string visit(SwitchStmt const&);
	std::string visit(BreakStmt const&);
	std::string visit(ContinueStmt const&);
	std::string visit(ReturnStmt const&);
	std::string visit(DoStmt const&);
	std::string visit(WhileStmt const&);
};
}
}
}