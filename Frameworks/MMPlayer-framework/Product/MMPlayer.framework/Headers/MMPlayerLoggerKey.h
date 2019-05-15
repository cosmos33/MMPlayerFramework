//
//  MMPlayerLoggerKey.h
//  ssss
//
//  Created by sunfei on 2019/4/29.
//  Copyright © 2019 sunfei. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const player_log_type;
extern NSString * const player_video_url;
extern NSString * const player_video_type;
extern NSString * const player_cdn_domain;
extern NSString * const player_network_type;
extern NSString * const player_error_code;
extern NSString * const player_extra_code;
extern NSString * const player_error_info;
extern NSString * const player_is_first_video_rendered;
extern NSString * const player_perf_stat_type;
extern NSString * const player_tcp_connect_cost_long;
extern NSString * const player_find_stream_info_cost;
extern NSString * const player_first_video_packet_cost;
extern NSString * const player_first_video_frame_cost;
extern NSString * const player_first_video_render_cost;
extern NSString * const player_first_audio_packet_cost;
extern NSString * const player_first_audio_frame_cost;
extern NSString * const player_first_audio_render_cost;
extern NSString * const player_total_recv_bytes;
extern NSString * const player_audio_recv_bytes;
extern NSString * const player_video_recv_bytes;
extern NSString * const player_video_duration;
extern NSString * const player_audio_duration;
extern NSString * const player_video_codec_id;
extern NSString * const player_video_codec_name;
extern NSString * const player_video_codec_level;
extern NSString * const player_video_codec_profile;
extern NSString * const player_audio_codec_id;
extern NSString * const player_audio_codec_name;
extern NSString * const player_use_proxy;
extern NSString * const player_audio_bitrate;
extern NSString * const player_video_bitrate;
extern NSString * const player_video_width;
extern NSString * const player_video_height;
extern NSString * const player_file_size;
extern NSString * const player_is_cache_hit;
extern NSString * const player_video_ffplay_codec_cost;
extern NSString * const player_video_cache_duration;
extern NSString * const player_audio_cache_duration;
extern NSString * const player_is_seeking;
extern NSString * const player_buffering_duration;
extern NSString * const player_preload_size;
extern NSString * const player_preload_audio_duration;
extern NSString * const player_preload_video_duration;
extern NSString * const player_video_toolbox_cost;
extern NSString * const player_app_ver_num;

// unused keys
extern NSString * const player_cdn_ip;
extern NSString * const player_video_media_codec_cost;
extern NSString * const player_video_cache_bytes;
extern NSString * const player_audio_cache_bytes;
