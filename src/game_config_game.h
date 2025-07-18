/*
 * This file is part of EasyRPG Player.
 *
 * EasyRPG Player is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EasyRPG Player is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with EasyRPG Player. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef EP_GAME_CONFIG_GAME_H
#define EP_GAME_CONFIG_GAME_H

/**
 * This class manages game specific configuration.
 * For engine specific settings see Game_Config.
 *
 * All settings here are currently readonly (To be set in EasyRPG.ini)
 *
 * @see Game_Config
 */

#include "config_param.h"
#include "filesystem_stream.h"

class CmdlineParser;

struct Game_ConfigGame {
	// FIXME? Editing these settings through the config scene is not supported

	BoolConfigParam new_game{ "Start new game", "Skips the title screen and starts a new game directly", "Game", "NewGame", false };
	StringConfigParam engine_str{ "Engine", "", "Game", "Engine", std::string() };
	BoolConfigParam fake_resolution{ "Fake Metrics", "Makes games run on higher resolutions (with some success)", "Game", "FakeResolution", false };
	BoolConfigParam patch_easyrpg{ "EasyRPG", "EasyRPG Engine Extensions", "Patch", "EasyRPG", false };
	BoolConfigParam patch_destiny{ "Destiny Patch", "", "Patch", "Destiny", false };
	BoolConfigParam patch_dynrpg{ "DynRPG", "", "Patch", "DynRPG", false };
	ConfigParam<int> patch_maniac{ "Maniac Patch", "", "Patch", "Maniac", 0 };
	BoolConfigParam patch_common_this_event{ "Common This Event", "Support \"This Event\" in Common Events", "Patch", "CommonThisEvent", false };
	BoolConfigParam patch_unlock_pics{ "Unlock Pictures", "Allow picture commands while a message is shown", "Patch", "PicUnlock", false };
	BoolConfigParam patch_key_patch{ "Ineluki Key Patch", "Support \"Ineluki Key Patch\"", "Patch", "KeyPatch", false };
	BoolConfigParam patch_rpg2k3_commands{ "RPG2k3 Event Commands", "Enable support for RPG2k3 event commands", "Patch", "RPG2k3Commands", false };
	ConfigParam<int> patch_anti_lag_switch{ "Anti-Lag Switch", "Disable event page refreshes when switch is set", "Patch", "AntiLagSwitch", 0 };
	ConfigParam<int> patch_direct_menu{ "Direct Menu", " Allows direct access to subscreens of the default menu", "Patch", "DirectMenu", 0 };

	ConfigParam<int> patch_encounter_random_alert_sw{ "Encounter Randomness Alert", "Set troop id to a variable, activate a switch and skip random battle", "Patch", "EncounterAlert.Switch", 0 };
	ConfigParam<int> patch_encounter_random_alert_var{ "Encounter Randomness Alert", "Set troop id to a variable, activate a switch and skip random battle", "Patch", "EncounterAlert.Var", 0 };

	ConfigParam<int> patch_monsca_maxhp{ "MonSca", "Scales enemy battle stats by variable value. (MaxHP)", "Patch", "MonSca.MaxHP", 0 };
	ConfigParam<int> patch_monsca_maxsp{ "MonSca", "Scales enemy battle stats by variable value. (MaxSP)", "Patch", "MonSca.MaxSP", 0 };
	ConfigParam<int> patch_monsca_atk{ "MonSca", "Scales enemy battle stats by variable value. (Attack)", "Patch", "MonSca.Attack", 0 };
	ConfigParam<int> patch_monsca_def{ "MonSca", "Scales enemy battle stats by variable value. (Defense)", "Patch", "MonSca.Defense", 0 };
	ConfigParam<int> patch_monsca_spi{ "MonSca", "Scales enemy battle stats by variable value. (Spirit)", "Patch", "MonSca.Spirit", 0 };
	ConfigParam<int> patch_monsca_agi{ "MonSca", "Scales enemy battle stats by variable value. (Agility)", "Patch", "MonSca.Agility", 0 };
	ConfigParam<int> patch_monsca_exp{ "MonSca", "Scales enemy battle stats by variable value. (Gained EXP)", "Patch", "MonSca.Experience", 0 };
	ConfigParam<int> patch_monsca_gold{ "MonSca", "Scales enemy battle stats by variable value. (Gained Money)", "Patch", "MonSca.Money", 0 };
	ConfigParam<int> patch_monsca_item{ "MonSca", "Scales enemy battle stats by variable value. (Gained Item)", "Patch", "MonSca.ItemId", 0 };
	ConfigParam<int> patch_monsca_droprate{ "MonSca", "Scales enemy battle stats by variable value. (Item Drop Rate)", "Patch", "MonSca.ItemDropRate", 0 };
	ConfigParam<int> patch_monsca_levelscaling{ "MonSca", "Scales enemy battle stats by variable value. (Alternate formula)", "Patch", "MonSca.LevelScaling", 0 };
	ConfigParam<int> patch_monsca_plus{ "MonSca", "Scale enemies individually based on troop index", "Patch", "MonSca.Plus", 0 };

	ConfigParam<int> patch_explus_var{ "EXPlus", "Boosts party EXP by set percentages", "Patch", "EXPlus.VarExpBoost", 0 };
	ConfigParam<int> patch_explusplus_var{ "EXPlus", "Allows for setting party index of given actors to a variable", "Patch", "EXPlus.VarActorInParty", 0 };

	ConfigParam<int> patch_guardrevamp_normal{ "GuardRevamp", "Changes damage calculation for defense situations (Normal)", "Patch", "GuardRevamp.NormalDefense", 0 };
	ConfigParam<int> patch_guardrevamp_strong{ "GuardRevamp", "Changes damage calculation for defense situations (Strong)", "Patch", "GuardRevamp.StrongDefense", 0 };

	// Command line only
	BoolConfigParam patch_support{ "Support patches", "When OFF all patch support is disabled", "", "", true };

	// Indicators of overridden settings to disable auto detection
	bool patch_override = false;

	int engine = 0;

	/**
	 * Initializes a game config from the config file in the game directory, then loads command line arguments.
	 */
	void Initialize(CmdlineParser& cp);

	/**
	 * Load configuration values from a stream;
	 *
	 * @param is stream to read from.
	 * @post values of this are updated with values found in the stream.
	 */
	void LoadFromStream(Filesystem_Stream::InputStream& is);

	/**
	 * Load configuration values from a command line arguments.
	 *
	 * @param cp the command line parser to use.
	 * @post values of this are updated with values found in command line args.
	 */
	void LoadFromArgs(CmdlineParser& cp);

	/** Outputs a list of active patches */
	void PrintActivePatches();
};

#endif
