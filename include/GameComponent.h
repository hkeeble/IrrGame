/**
 * @file
 * @author
 * @brief
 */

namespace IrrGame
{
	class GameComponent
	{
	public:
		GameComponent() : visible(true), enabled(true) { };
		virtual ~GameComponent();

		void SetVisible(bool visible) { this->visible = visible; }
		void SetEnabled(bool enabled) { this->enabled = enabled; }

		virtual void Update() = 0;
		virtual void Render() = 0;

	private:
		bool visible;
		bool enabled;
	};
}