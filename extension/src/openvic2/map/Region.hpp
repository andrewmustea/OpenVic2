#pragma once

#include <set>

#include "openvic2/map/Province.hpp"

namespace OpenVic2 {

	struct ProvinceSet {
	protected:
		std::set<Province*> provinces;
	public:
		size_t get_province_count() const;
		bool contains_province(Province const* province) const;
		std::set<Province*> const& get_provinces() const;
	};

	/* REQUIREMENTS:
	 * MAP-6, MAP-44, MAP-48
	 */
	struct Region : HasIdentifier, ProvinceSet {
		friend struct Map;
	private:
		Region(std::string const& new_identifier);
	public:
		Province::colour_t get_colour() const;
	};
}