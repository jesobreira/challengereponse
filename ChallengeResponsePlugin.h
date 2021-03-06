/* 
 * Adium is the legal property of its developers, whose names are listed in the copyright file included
 * with this source distribution.
 * 
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program; if not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#import <Adium/AIPlugin.h>
#import <Adium/AIChatControllerProtocol.h>

#define	CHALLENGE_RESPONSE_PREFERENCE_GROUP			@"ChallengeResponse"
#define CHALLENGE_RESPONSE_PREFERENCE_ENABLED		@"Enabled"
#define CHALLENGE_RESPONSE_PREFERENCE_LOGENABLED	@"LoggingEnabled"
#define CHALLENGE_RESPONSE_PREFERENCE_HIDEBLOCKED	@"HideBlocked"
#define CHALLENGE_RESPONSE_PREFERENCE_JUSTCONTAIN	@"MustJustContain"
#define CHALLENGE_RESPONSE_PREFERENCE_CHALLENGE		@"ChallengeText"
#define CHALLENGE_RESPONSE_PREFERENCE_RESPONSE		@"ResponseText"
#define CHALLENGE_RESPONSE_PREFERENCE_WHITELIST		@"Whitelist"
#define CHALLENGE_RESPONSE_CHAT_NAME				@"ChallengeResponse"

@interface ChallengeResponsePlugin : AIPlugin {
	NSMenuItem				*menuItem_challengeResponse;
	
	NSMutableDictionary		*greyListContent;
	NSArray					*whiteList;
	
	NSString				*challengeMessage;
	NSString				*responseMessage;
	
	BOOL					loggingEnabled;
	BOOL					enabled;
	BOOL					hideBlocked;
	BOOL					mustJustContain;
	
	NSMutableDictionary		*openChats;
}

- (BOOL)listObjectIsWhitelisted:(AIListObject *)listObject;
- (void)addListObjectToWhitelist:(AIListObject *)listObject;

- (BOOL)savedGreyListExistsForListObject:(AIListObject *)listObject;
- (void)addToGreyList:(AIContentObject *)contentObject;
- (void)displayGreyListAndClearForObjectID:(NSString *)objectID;

@end
