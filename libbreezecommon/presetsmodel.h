#ifndef BREEZE_PRESETSMODEL_H
#define BREEZE_PRESETSMODEL_H

/*
 * SPDX-FileCopyrightText: 2023 Paul A McAuley <kde@paulmcauley.com>
 *
 * SPDX-License-Identifier: MIT
 */

#include "breeze.h"
#include "breezecommon_export.h"

namespace Breeze
{

enum struct BREEZECOMMON_EXPORT PresetsErrorFlag {
    None,
    InvalidGlobalGroup,
    InvalidVersion,
    InvalidGroup,
    InvalidKey,
};

/**
 * @brief Functions to read and write Presets from/to config file within Klassy
 */
class BREEZECOMMON_EXPORT PresetsModel
{
public:
    static QString presetGroupName(const QString str);
    static void writePreset(KCoreConfigSkeleton *skeleton, KConfig *config, const QString &presetName);
    static void writePreset(KCoreConfigSkeleton *skeleton, KConfig *config, const QString &presetName, const QStringList &whiteListKeys);
    static void readPreset(KCoreConfigSkeleton *skeleton, KConfig *config, const QString &presetName);
    static void deletePreset(KConfig *config, const QString &presetName);
    static void deleteBundledPresets(KConfig *config);
    static QStringList readPresetsList(KConfig *config);
    static bool isPresetPresent(KConfig *config, const QString &presetName);
    static bool isPresetFromFilePresent(KConfig *config, const QString &presetFileName, QString &presetName);
    static void exportPreset(KConfig *config, const QString &presetName, const QString &fileName);
    static PresetsErrorFlag
    importPreset(KConfig *config, const QString &fileName, QString &presetName, QString &error, bool forceInvalidVersion = false, bool markAsBundled = false);
    static bool isKeyValid(const QString &key);
    static bool isEnumValueValid(const QString &key, const QString &property);
};

}

#endif
