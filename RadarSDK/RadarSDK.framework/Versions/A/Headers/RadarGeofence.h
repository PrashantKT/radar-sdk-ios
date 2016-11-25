//
//  RadarGeofence.h
//  RadarSDK
//
//  Copyright © 2016 Radar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RadarGeofence : NSObject

- (instancetype _Nullable)initWithId:(NSString * _Nonnull)_id description:(NSString * _Nonnull)description tag:(NSString * _Nullable)tag externalId:(NSString * _Nullable)externalId;

/**
 * @abstract The unique ID for the geofence, provided by Radar.
 */
@property (nonnull, copy, nonatomic, readonly) NSString *_id;

/**
 * @abstract A description for the geofence. Not to be confused with the NSObject description property.
 */
@property (nonnull, copy, nonatomic, readonly) NSString *_description;

/**
 * @abstract An optional group for the geofence.
 */
@property (nullable, copy, nonatomic, readonly) NSString *tag;

/**
 * @abstract An optional external ID for the geofence.
 */
@property (nullable, copy, nonatomic, readonly) NSString *externalId;

@end
