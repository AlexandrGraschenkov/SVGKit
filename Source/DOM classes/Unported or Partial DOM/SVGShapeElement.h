/**
 SVGShapeElement
 
 The majority of real-world SVG elements are Shapes: arbitrary shapes made out of line segments, curves, etc.
 
 
 Data:
 - "pathRelative": the actual path as parsed from the original file. THIS MIGHT NOT BE NORMALISED (maybe a future feature)
 
 - "opacity", "fillColor", "strokeColor", "strokeWidth", "fillPattern", "fillType": SVG info telling you how to paint the shape
 */

#import "SVGElement.h"
#import "SVGLayeredElement.h"
#import "SVGUtils.h"

@class SVGGradientElement;
@class SVGKPattern;

typedef enum {
	SVGFillTypeUnspecified,
	SVGFillTypeNone,
	SVGFillTypeSolid,
	SVGFillTypeURL
} SVGFillType;

@interface SVGShapeElement : SVGElement < SVGLayeredElement >
{
	/* FIXME: are any of these private elements in the SVG spec? */
	NSString *_styleClass;
	CGRect _layerRect;
}

@property (nonatomic, readwrite) CGFloat opacity;

@property (nonatomic, readwrite) SVGFillType fillType;
@property (nonatomic, readwrite) SVGColor fillColor;
@property (nonatomic, readwrite, retain) SVGKPattern* fillPattern;
@property (nonatomic, readwrite, retain) NSString* fillId;

@property (nonatomic, readwrite) CGFloat strokeWidth;
@property (nonatomic, readwrite) SVGColor strokeColor;

@property (nonatomic, readonly) CGPathRef pathRelative;

/*!
 The provided path will be cloned, and set as the new "pathRelative"
 
 The provided path MUST already be in the local co-ordinate space, i.e. when rendering,
 0,0 in this path will be transformed by the local transform, and the parent's
 transform, and all grandparents in the tree, etc
 */
- (void)setPathByCopyingPathFromLocalSpace:(CGPathRef)aPath;

@end