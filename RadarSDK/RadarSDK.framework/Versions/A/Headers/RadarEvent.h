//
//  RadarEvent.h
//  RadarSDK
//
//  Copyright © 2016 Radar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "RadarUser.h"
#import "RadarGeofence.h"
#import "RadarPlace.h"

/**
 Represents a change in user state. For more information, see https://radar.io/documentation.
 
 @see https://radar.io/documentation
 */
@interface RadarEvent : NSObject

/**
 The types for events.
 */
typedef NS_ENUM(NSInteger, RadarEventType) {
    /// Unknown
    RadarEventTypeUnknown NS_SWIFT_NAME(unknown),
    /// `user.entered_geofence`
    RadarEventTypeUserEnteredGeofence NS_SWIFT_NAME(userEnteredGeofence),
    /// `user.exited_geofence`
    RadarEventTypeUserExitedGeofence NS_SWIFT_NAME(userExitedGeofence),
    /// `user.entered_home`
    RadarEventTypeUserEnteredHome NS_SWIFT_NAME(userEnteredHome),
    /// `user.exited_home`
    RadarEventTypeUserExitedHome NS_SWIFT_NAME(userExitedHome),
    /// `user.entered_office`
    RadarEventTypeUserEnteredOffice NS_SWIFT_NAME(userEnteredOffice),
    /// `user.exited_office`
    RadarEventTypeUserExitedOffice NS_SWIFT_NAME(userExitedOffice),
    /// `user.started_traveling`
    RadarEventTypeUserStartedTraveling NS_SWIFT_NAME(userStartedTraveling),
    /// `user.stopped_traveling`
    RadarEventTypeUserStoppedTraveling NS_SWIFT_NAME(userStoppedTraveling),
    /// `user.entered_place`
    RadarEventTypeUserEnteredPlace NS_SWIFT_NAME(userEnteredPlace),
    /// `user.exited_place`
    RadarEventTypeUserExitedPlace NS_SWIFT_NAME(userExitedPlace),
};

/**
 The confidence levels for events.
 */
typedef NS_ENUM(NSInteger, RadarEventConfidence) {
    /// Unknown confidence
    RadarEventConfidenceNone NS_SWIFT_NAME(none) = 0,
    /// Low confidence
    RadarEventConfidenceLow NS_SWIFT_NAME(low) = 1,
    /// Medium confidence
    RadarEventConfidenceMedium NS_SWIFT_NAME(medium) = 2,
    /// High confidence
    RadarEventConfidenceHigh NS_SWIFT_NAME(high) = 3
};

/**
 The verification types for events.
 */
typedef NS_ENUM(NSInteger, RadarEventVerification) {
    /// Accept event
    RadarEventVerificationAccept NS_SWIFT_NAME(accept) = 1,
    /// Unverify event
    RadarEventVerificationUnverify NS_SWIFT_NAME(unverify) = 0,
    /// Reject event
    RadarEventVerificationReject NS_SWIFT_NAME(reject) = -1
};

/**
 The Radar ID of the event.
 */
@property (nonnull, copy, nonatomic, readonly) NSString *_id;

/**
 The datetime when the event was created.
 */
@property (nonnull, copy, nonatomic, readonly) NSDate *createdAt;

/**
 A boolean indicating whether the event was generated with your live API key.
 */
@property (assign, nonatomic, readonly) BOOL live;

/**
 The type of the event.
 */
@property (assign, nonatomic, readonly) RadarEventType type;

/**
 The geofence for which the event was generated. May be `nil` for non-geofence events.
 */
@property (nullable, strong, nonatomic, readonly) RadarGeofence *geofence;

/**
 The place for which the event was generated. May be `nil` for non-place events.
 */
@property (nullable, strong, nonatomic, readonly) RadarPlace *place;

/**
 For place entry events, alternate place candidates. May be `nil` for non-place events.
 */
@property (nullable, strong, nonatomic, readonly) NSArray<RadarPlace *> *alternatePlaces;

/**
 For accepted place entry events, the verified place. May be `nil` for non-place events or unverified events.
 */
@property (nullable, strong, nonatomic, readonly) RadarPlace *verifiedPlace;

/**
 The verification of the event.
 */
@property (assign, nonatomic, readonly) RadarEventVerification verification;

/**
 The confidence level of the event.
 */
@property (assign, nonatomic, readonly) RadarEventConfidence confidence;

/**
 The duration between entry and exit events, in minutes, for exit events. 0 for entry events.
 */
@property (assign, nonatomic, readonly) float duration;

/**
 The location of the event.
 */
@property (nonnull, strong, nonatomic, readonly) CLLocation *location;

@end
