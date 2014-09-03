// vim: set ts=4 sw=4 tw=99 noet :
// =============================================================================
// SourceMod
// Copyright (C) 2004-2014 AlliedModders LLC.  All rights reserved.
// =============================================================================
//
// This program is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License, version 3.0, as published by the
// Free Software Foundation.
// 
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
// details.
//
// You should have received a copy of the GNU General Public License along with
// this program.  If not, see <http://www.gnu.org/licenses/>.
//
// As a special exception, AlliedModders LLC gives you permission to link the
// code of this program (as well as its derivative works) to "Half-Life 2," the
// "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
// by the Valve Corporation.  You must obey the GNU General Public License in
// all respects for all other code used.  Additionally, AlliedModders LLC grants
// this exception to all derivative works.  AlliedModders LLC defines further
// exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
// or <http://www.sourcemod.net/license.php>.

#ifndef _include_sourcemod_core_vprof_bridge_h_
#define _include_sourcemod_core_vprof_bridge_h_

#include <sp_vm_api.h>
#include "sm_globals.h"
#include <am-utility.h>

class VProfTool
	: public IProfilingTool,
	  public SMGlobalClass
{
public:
	VProfTool();

	// IProfilingTool
	const char *Name() KE_OVERRIDE;
	const char *Description() KE_OVERRIDE;
	bool Start() KE_OVERRIDE;
	void Stop(void (*render)(const char *fmt, ...)) KE_OVERRIDE;
	void Dump() KE_OVERRIDE;
	bool IsActive() KE_OVERRIDE;
	bool IsAttached() KE_OVERRIDE;
	void EnterScope(const char *group, const char *name) KE_OVERRIDE;
	void LeaveScope() KE_OVERRIDE;
	void RenderHelp(void (*render)(const char *fmt, ...)) KE_OVERRIDE;

	// SMGlobalClass
	void OnSourceModAllInitialized() KE_OVERRIDE;

private:
	bool active_;
};

#endif // _include_sourcemod_core_vprof_bridge_h_