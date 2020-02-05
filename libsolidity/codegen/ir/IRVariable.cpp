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
#include <libsolidity/codegen/ir/IRVariable.h>
#include <libsolidity/ast/Types.h>
#include <boost/range/adaptor/transformed.hpp>
#include <libsolutil/StringUtils.h>

using namespace std;
using namespace solidity;
using namespace solidity::frontend;
using namespace solidity::util;

std::string IRVariable::commaSeparatedList() const
{
	solAssert(m_type, "");
	return joinHumanReadable(
		m_type->stackSlotNames() | boost::adaptors::transformed([&](std::string const& _slotName) {
			if (_slotName.empty())
				return m_baseName;
			else
				return m_baseName + '_' + _slotName;
		})
	);
}

Type const& IRVariable::type() const
{
	solAssert(m_type, "");
	return *m_type;
}

std::string IRVariable::operator[](std::string const &_part) const
{
	solAssert(contains(m_type->stackSlotNames(), _part), "");
	if (_part.empty())
		return m_baseName;
	else
		return m_baseName + '_' + _part;
}

/*
std::string IRVariable::name() const
{
	solAssert(m_type && m_type->sizeOnStack() == 1, "Single variable name requested for multi-slot variable.");
	if (m_type->stackSlotNames().front().empty())
		return m_baseName;
	else
		return m_baseName + '_' + m_type->stackSlotNames().front();
}
*/