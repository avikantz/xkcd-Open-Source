//
//  RequestManager.h
//  xkcd Open Source
//
//  Created by Mike on 5/14/15.
//  Copyright (c) 2015 Mike Amaral. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AFNetworking.h>
#import "Comic.h"

@class Assembler;

// TODO: Refactor this class.

static NSString * const kRequestManagerErrorDomain = @"Request Manager";
static NSString * const kRequestManagerUserInfoKey = @"error";
static NSString * const kRequestManagerNilTokenErrorMessage = @"Request Manager";

static NSInteger const kRequestManagerErrorCode = -1;

static NSString * const kDefaultContentType = @"application/x-www-form-urlencoded";
static NSString * const kContentTypeKey = @"Content-Type";

@interface RequestManager : NSObject

@property (nonatomic, strong) AFHTTPRequestOperationManager *manager;

- (instancetype)initWithAssembler:(Assembler *)assembler;

#pragma mark - Downloading comics

- (void)downloadComicsSince:(NSInteger)since completionHandler:(void (^)(NSError *error, NSArray *comicDicts))handler;


#pragma mark - Device tokens

- (void)sendDeviceToken:(NSString *)token completionHandler:(void (^)(NSError *error))handler;

@end
