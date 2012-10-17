//
//  TMAPIClient.h
//  TumblrSDK
//
//  Created by Bryan Irace on 8/26/12.
//  Copyright (c) 2012 Bryan Irace. All rights reserved.
//

typedef void (^TMAPICallback)(id, NSError *error);

@interface TMAPIClient : NSObject

@property (nonatomic, copy) NSString *OAuthConsumerKey;
@property (nonatomic, copy) NSString *OAuthConsumerSecret;
@property (nonatomic, copy) NSString *OAuthToken;
@property (nonatomic, copy) NSString *OAuthTokenSecret;

@property (nonatomic, readonly) JXHTTPOperationQueue *queue;

+ (TMAPIClient *)sharedInstance;

- (void)sendRequest:(JXHTTPOperation *)request callback:(TMAPICallback)callback;

/** @name Authentication */

- (JXHTTPOperation *)xAuthRequest:(NSString *)userName password:(NSString *)password;
- (JXHTTPOperation *)xAuth:(NSString *)userName password:(NSString *)password callback:(TMAPICallback)callback;

/** @name User */

- (JXHTTPOperation *)userInfoRequest;
- (void)userInfo:(TMAPICallback)callback;

- (JXHTTPOperation *)dashboardRequest:(NSDictionary *)parameters;
- (void)dashboard:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)likesRequest:(NSDictionary *)parameters;
- (void)likes:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)followingRequest:(NSDictionary *)parameters;
- (void)following:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)followRequest:(NSString *)blogName;
- (void)follow:(NSString *)blogName callback:(TMAPICallback)callback;

- (JXHTTPOperation *)unfollowRequest:(NSString *)blogName;
- (void)unfollow:(NSString *)blogName callback:(TMAPICallback)callback;

- (JXHTTPOperation *)likeRequest:(NSString *)postID reblogKey:(NSString *)reblogKey;
- (void)like:(NSString *)postID reblogKey:(NSString *)reblogKey callback:(TMAPICallback)callback;

- (JXHTTPOperation *)unlikeRequest:(NSString *)postID reblogKey:(NSString *)reblogKey;
- (void)unlike:(NSString *)postID reblogKey:(NSString *)reblogKey callback:(TMAPICallback)callback;

/** @name Blog */

- (JXHTTPOperation *)blogInfoRequest:(NSString *)blogName;
- (void)blogInfo:(NSString *)blogName callback:(TMAPICallback)callback;

- (JXHTTPOperation *)followersRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)followers:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

// TODO: Document that this result will be NSData
- (JXHTTPOperation *)avatarRequest:(NSString *)blogName size:(int)size;
- (void)avatar:(NSString *)blogName size:(int)size callback:(TMAPICallback)callback;

- (JXHTTPOperation *)postsRequest:(NSString *)blogName type:(NSString *)type parameters:(NSDictionary *)parameters;
- (void)posts:(NSString *)blogName type:(NSString *)type parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)queueRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)queue:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)draftsRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)drafts:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)submissionsRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)submissions:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

/** @name Posting */

- (JXHTTPOperation *)editPostRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)editPost:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)reblogPostRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)reblogPost:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)deletePostRequest:(NSString *)blogName id:(NSString *)postID;
- (void)deletePost:(NSString *)blogName id:(NSString *)postID callback:(TMAPICallback)callback;

- (JXHTTPOperation *)postRequest:(NSString *)blogName type:(NSString *)type parameters:(NSDictionary *)parameters;
- (void)post:(NSString *)blogName type:(NSString *)type parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)textRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)text:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)quoteRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)quote:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)linkRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)link:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)chatRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)chat:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)audioRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)audio:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)videoRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)video:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

- (JXHTTPOperation *)photoRequest:(NSString *)blogName parameters:(NSDictionary *)parameters;
- (void)photo:(NSString *)blogName parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

/** @name Tagging */

- (JXHTTPOperation *)taggedRequest:(NSString *)tag parameters:(NSDictionary *)parameters;
- (void)tagged:(NSString *)tag parameters:(NSDictionary *)parameters callback:(TMAPICallback)callback;

@end
