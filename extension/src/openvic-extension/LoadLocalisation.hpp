#pragma once

#include <godot_cpp/classes/translation.hpp>

#include <openvic-simulation/dataloader/Dataloader.hpp>

namespace OpenVic {
	class LoadLocalisation : public godot::Object {

		GDCLASS(LoadLocalisation, godot::Object)

		static LoadLocalisation* singleton;

		godot::Error _load_file_into_translation(godot::String const& file_path, godot::Ref<godot::Translation> translation) const;
		godot::Ref<godot::Translation> _get_translation(godot::String const& locale) const;

	protected:
		static void _bind_methods();

	public:
		static LoadLocalisation* get_singleton();

		LoadLocalisation();
		~LoadLocalisation();

		godot::Error load_file(godot::String const& file_path, godot::String const& locale) const;
		godot::Error load_locale_dir(godot::String const& dir_path, godot::String const& locale) const;
		godot::Error load_localisation_dir(godot::String const& dir_path) const;

		static bool add_message(std::string_view key, Dataloader::locale_t locale, std::string_view localisation);
	};
}
