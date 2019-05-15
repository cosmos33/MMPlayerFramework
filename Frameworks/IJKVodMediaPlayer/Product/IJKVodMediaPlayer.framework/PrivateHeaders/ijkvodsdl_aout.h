/*****************************************************************************
 * ijksdl_aout.h
 *****************************************************************************
 *
 * copyright (c) 2013 Zhang Rui <bbcallen@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef ijkvodsdl_aout_h
#define ijkvodsdl_aout_h

#include "ijkvodsdl_audio.h"
#include "ijkvodsdl_class.h"
#include "ijkvodsdl_mutex.h"

typedef struct SDL_Aout_Opaque SDL_Aout_Opaque;
typedef struct SDL_Aout SDL_Aout;
typedef struct SDL_Aout {
    SDL_mutex *mutex;
    double     minimal_latency_seconds;

    SDL_Class       *opaque_class;
    SDL_Aout_Opaque *opaque;
    void (*free_l)(SDL_Aout *vout);
    int (*open_audio)(SDL_Aout *aout, const SDL_AudioSpec *desired, SDL_AudioSpec *obtained);
    void (*pause_audio)(SDL_Aout *aout, int pause_on);
    void (*flush_audio)(SDL_Aout *aout);
    void (*set_volume)(SDL_Aout *aout, float left, float right);
    void (*close_audio)(SDL_Aout *aout);

    double (*func_get_latency_seconds)(SDL_Aout *aout);
    void   (*func_set_default_latency_seconds)(SDL_Aout *aout, double latency);
    
    void   (*func_set_playback_volume)(SDL_Aout *aout, float playbackVolume);
} SDL_Aout;

int VODSDL_AoutOpenAudio(SDL_Aout *aout, const SDL_AudioSpec *desired, SDL_AudioSpec *obtained);
void VODSDL_AoutPauseAudio(SDL_Aout *aout, int pause_on);
void VODSDL_AoutFlushAudio(SDL_Aout *aout);
void VODSDL_AoutSetStereoVolume(SDL_Aout *aout, float left_volume, float right_volume);
void VODSDL_AoutCloseAudio(SDL_Aout *aout);
void VODSDL_AoutFree(SDL_Aout *aout);
void VODSDL_AoutFreeP(SDL_Aout **paout);

double VODSDL_AoutGetLatencySeconds(SDL_Aout *aout);
void   VODSDL_AoutSetDefaultLatencySeconds(SDL_Aout *aout, double latency);

void   VODSDL_AoutSetPlaybackVolume(SDL_Aout *aout, float volume);

#endif
