/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/* Copyright (C) 2012-2014 Freescale Semiconductor, Inc. */

#ifndef ANDROID_INCLUDE_IMX_CONFIG_VT1613_H
#define ANDROID_INCLUDE_IMX_CONFIG_VT1613_H

#include "audio_hardware.h"


#define MIXER_VT1613_SPEAKER_VOLUME                 "Speaker Playback Volume"
#define MIXER_VT1613_SPEAKER_SWITCH                 "Speaker Playback Switch"
#define MIXER_VT1613_HEADPHONE_VOLUME               "Headphone Playback Volume"
#define MIXER_VT1613_HEADPHONE_SWITCH               "Headphone Playback Switch"
#define MIXER_VT1613_PCM_VOLUME                     "PCM Playback Volume"
#define MIXER_VT1613_PCM_SWITCH                     "PCM Playback Switch"

#define MIXER_VT1613_CAPTURE_SWITCH                 "Record Capture Switch"
#define MIXER_VT1613_CAPTURE_VOLUME                 "Record Capture Volume"
#define MIXER_VT1613_RECORD_MUX                     "Record Mux"
#define MIXER_VT1613_MIC_SELECT                     "Mic Select"
#define MIXER_VT1613_STEREOMIC_RIGHT_SWITCH         "Mic/StereoMic_R Switch"
#define MIXER_VT1613_STEREOMIC_RIGHT_VOLUME         "Mic/StereoMic_R Volume"
#define MIXER_VT1613_STEREOMIC_LEFT_SWITCH          "StereoMic_L Switch"
#define MIXER_VT1613_STEREOMIC_LEFT_VOLUME          "StereoMic_L Volume"


static struct route_setting speaker_output_vt1613[] = {
    {
        .ctl_name = MIXER_VT1613_PCM_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_VT1613_SPEAKER_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_VT1613_SPEAKER_VOLUME,
        .intval = 31,
    },
    {
        .ctl_name = MIXER_VT1613_PCM_VOLUME,
        .intval = 0,
    },
    {
        .ctl_name = NULL,
    },
};

static struct route_setting mm_main_mic_input_vt1613[] = {
    {
        .ctl_name = MIXER_VT1613_RECORD_MUX,
        .intval = 0,
    },
    {
        .ctl_name = MIXER_VT1613_MIC_SELECT,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_VT1613_CAPTURE_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_VT1613_STEREOMIC_RIGHT_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_VT1613_STEREOMIC_LEFT_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_VT1613_CAPTURE_VOLUME,
        .intval = 0,
    },
    {
        .ctl_name = MIXER_VT1613_STEREOMIC_RIGHT_VOLUME,
        .intval = 8,
    },
    {
        .ctl_name = MIXER_VT1613_STEREOMIC_LEFT_VOLUME,
        .intval = 8,
    },
    {
        .ctl_name = NULL,
    },
};

/* ALSA cards for IMX, these must be defined according different board / kernel config*/
static struct audio_card  vt1613_card = {
    .name = "vt1613-audio",
    .driver_name = "vt1613-audio",
    .supported_out_devices = AUDIO_DEVICE_OUT_SPEAKER,
    .supported_in_devices = AUDIO_DEVICE_IN_BUILTIN_MIC,
    .defaults            = NULL,
    .bt_output           = NULL,
    .speaker_output      = speaker_output_vt1613,
    .hs_output           = NULL,
    .earpiece_output     = NULL,
    .vx_hs_mic_input     = NULL,
    .mm_main_mic_input   = mm_main_mic_input_vt1613,
    .vx_main_mic_input   = NULL,
    .mm_hs_mic_input     = NULL,
    .vx_bt_mic_input     = NULL,
    .mm_bt_mic_input     = NULL,
    .card                = 0,
    .out_rate            = 0,
    .out_channels        = 0,
    .out_format          = 0,
    .in_rate             = 0,
    .in_channels         = 0,
    .in_format           = 0,
};

#endif  /* ANDROID_INCLUDE_IMX_CONFIG_VT1613_H */
